#ifndef JetAlgorithms_CMSKtJetAlgorithm_h
#define JetAlgorithms_CMSKtJetAlgorithm_h

/** \class CMSKtJetAlgorithm
 *
 * \short CMS Kt algorithm.
 *
 * CMSKtJetAlgorithm is an interface class between the generic
 * KtJet algorithm (http://www.ktjets.org) and the CMS EDM Framework
 * The implementation of this class is inspired on the work
 * previously done by Arno Heister in the ORCA framwork
 *
 * This class prepares a list of constituents as KtLorentzVector
 * for the KtJets algorithm from a collection of CaloTowers. Then, 
 * the KtJet algorithm is inovked to reconstruct the Jets.
 * These jets are obtained as an array of KtLorentzVectors. Finally, the 
 * CMSKtJetAlgorithm class "casts" these Jets to CaloJets. 
 *
 * \author Fernando Varela Rodriguez, Boston University
 *
 * \version   1st Version April 22, 2005.
 * \version   R. Harris, October 19, 2005 modified to use real CaloTowers
 * \version   F.Ratnikov, Mar. 8, 2006. Correct bug, work from Candidate
 * $Id$
 *
 ************************************************************/
 
#include "RecoJets/JetAlgorithms/interface/ProtoJet.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"

#include <vector>
 
class CMSKtJetAlgorithm
{
public:
  typedef std::vector <const reco::Candidate*> InputCollection;
  typedef std::vector<ProtoJet> OutputCollection;

  /** Default constructor    */
  CMSKtJetAlgorithm();

  /** Constructor
  \param aKtJetAngle Controls the angular defintions of the variables d_kB and d_kl.
  Values: 1- Angular, 2- Delta R and 3- QCD emission schemas
  \param aKtJetRecom Defines the recombination schema. Values: 1- E, 2- Pt, 3- pt^2,
  4- Et, 5- Et^2
  \param aKtJetECut  Energy threshold of the input constituents.*/
  CMSKtJetAlgorithm(int aKtJetAngle,int aKtJetRecom, float aKtJetECut);

  /** Constructor
  \param aKtJetAngle Controls the angular defintions of the variables d_kB and d_kl.
  Values: 1- Angular, 2- Delta R and 3- QCD emission schemas
  \param aKtJetRecom Defines the recombination schema. Values: 1- E, 2- Pt, 3- pt^2,
  4- Et, 5- Et^2
  \param aKtJetECut  Energy threshold of the input constituents.
  \param aKtJetRParameter Scale factor of the Kt algorithm. Default value is 1 according
  to the Snow-mass convention*/
  CMSKtJetAlgorithm(int aKtJetAngle,int aKtJetRecom, float aKtJetECut, float aKtJetRParameter = 1.);  
  /** Default constructor    */
  ~CMSKtJetAlgorithm() {};
  
  /** run: Find the ProtoJets from the collection of input Candidates.
  \param fInput Input collection of Candidates. Energy threshold cut will be applied.
  \param fOutput Output collection of ProtoJets. 
  */
  void run (const InputCollection& fInput, OutputCollection* fOutput);
  
  /** setKtJetAngle: Sets the Angular schema
  \param aKtJetAngle Controls the angular defintions of the variables d_kB and d_kl.
  Values: 1- Angular, 2- Delta R and 3- QCD emission schemas */
  void setKtJetAngle(int aKtJetAngle);
  
  /** setKtJetRecom: Sets the recombination schema
  \param aKtJetRecom Defines the recombination schema. Values: 1- E, 2- Pt, 3- pt^2,
  4- Et, 5- Et^2 */
  void setKtJetRecom(int aKtJetRecom);

  /** setKtJetRParameter: Sets the scale factor, R.
  \param aKtJetRParameter Scale factor of the Kt algorithm. Default value is 1 according
  to the Snow-mass convention*/
  void setKtJetRParameter(float aKtJetRParameter);

  /** setKtJetECut: Sets the scale tower energy thrshold cut.
  \param aKtJetECut  Energy threshold of the input constituents.*/
  void setKtJetECut(float aKtJetECut);
  
private:
  /** theKtJetType: Type of collision. Always 4 -> pp collision    */
  int   theKtJetType;

  /** theKtJetAngle: Angular schema  */
  int   theKtJetAngle;

  /** theKtJetRecom: Jet recombination schema    */
  int   theKtJetRecom;

  /** theKtJetRParam: Scale factor    */
  float theKtJetRParameter;

  /** theKtJetECut: Energy threshold of the input constituents    */
  float theKtJetECut;
};
#endif
