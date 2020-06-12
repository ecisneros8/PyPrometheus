#include "cantera/IdealGasMix.h"
#include "cantera/kinetics.h"
#include "cantera/thermo/speciesThermoTypes.h"
#include "utils.h"

class qssPrometheus
{
 public:
    
  qssPrometheus(bool& ooriented,
		bool& templated,
		int& nrep,
		std::string& mech,
		Cantera::IdealGasMix& gas)
    {
    m_gas  = &gas;
    m_mech = mech;
    m_ooriented = ooriented;
    m_templated = templated;
    if( m_templated == true ) {
      m_baseType = "ModelType";
      m_dataType = "DataType";      
    } else {
      m_baseType = "double";
      m_dataType = "double";
    }
    m_nrep = nrep;
    m_nqss = m_gas->nSpecies() - nrep;
  };

  void greetings();
  
  void writeMech();

  void writeDefs(std::ostream& out);

  void writeKineticsHeader(std::ostream& out);

  void writeThermoHeader(std::ostream& out);

  void writeKinetics(std::ostream& out);
  
  void writeThermo(std::ostream& out);

  void writeFalloffKinetics(std::ostream& out);

  void writeRateCoefficients(std::ostream& out);

  void writeArrheniusKinetics(int& rxn,
			      std::shared_ptr<Cantera::Reaction>& reaction,
			      std::ostream& out);

  void writeNetRatesOfProgress(std::ostream& out);
  
  void writeNetProductionRates(std::ostream& out);

  void writeSpeciesSpecificHeats(std::ostream& out);

  void writeSpeciesEnthalpies(std::ostream& out);

  void writeSpeciesEntropies(std::ostream& out);

  void writeSpeciesGibbs(std::ostream& out);

  void writeEquilibriumConstants(std::ostream& out);

  void writeNewtonTemperature(std::ostream& out);

  void getThirdBodyEfficiencies(std::shared_ptr<Cantera::Reaction>& reaction,
				std::vector<std::vector<double> >& tbrEfficiencies);
  
  void getParticipatingSpecies(std::shared_ptr<Cantera::Reaction>& reaction,
			       std::vector<int>& reacIndices,
			       std::vector<int>& prodIndices);

  int nFalloff();

  void writeFunctionName(std::ostream& out,
			 const std::string& className,
			 const std::string& funName);
  
 private:
  bool        m_ooriented;
  bool        m_templated;
  int         m_nrep;
  int         m_nqss;
  std::string m_mech;
  std::string m_baseType;
  std::string m_dataType;
  std::map<int, std::vector<std::string> > m_rhs;
  Cantera::IdealGasMix* m_gas;
    
};