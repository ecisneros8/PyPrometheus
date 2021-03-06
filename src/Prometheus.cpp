#include "Prometheus.h"

void Prometheus::Greetings() {

  std::cout.setf(std::ios::scientific);
  std::cout.precision(6);

  std::string prometheus = "Prometheus: ";
  std::cout << prometheus << "Welcome..." << std::endl;
  std::cout << prometheus << "Working with " << m_mech  << " mech..." << std::endl;
  std::cout << prometheus << "Number of species:   "    << m_thermo->nSpecies()     << std::endl;
  std::cout << prometheus << "Number of elements:  "    << m_thermo->nElements()    << std::endl;
  std::cout << prometheus << "Number of reactions: "    << m_kinetics->nReactions() << std::endl;
  
  std::cout << prometheus << "The implementation will ";
  if( m_ooriented == false ) { std::cout << "not "; } 
  std::cout << "be object-oriented..." << std::endl;
  
  std::cout << prometheus << "The implementation will ";
  if( m_templated == false ) { std::cout << "not "; }
  std::cout << "be templated..." << std::endl;
  
}

void Prometheus::WriteMech() {

  std::string   filename;
  std::ofstream out;
  out.setf( std::ios::scientific );
  out.precision(6);

  Greetings();

  filename = m_mech + ".H";
  out.open( filename.c_str() );
  WriteDefinitions( out );
  
  ///
  /// Thermo
  ///
  WriteThermo( out );
  
  ///
  /// Kinetics
  ///
  WriteKinetics( out );

  ///
  /// Transport
  ///
  WriteTransport( out );
  
}

///
/// Definitions
///
void Prometheus::WriteDefinitions(std::ostream& out) {

  
  out << "... Nothing to see here yet ... " << std::endl;
  
}

///
/// Thermo
///
void Prometheus::WriteThermo(std::ostream& out) {

  std::string prometheus = "Prometheus:Thermo: ";
  
  std::cout << prometheus << " Writing specific heats ... " << std::endl;
  WriteSpeciesSpecificHeats( out );
  
  std::cout << prometheus << " Writing enthalpies ... " << std::endl;
  WriteSpeciesEnthalpies( out );

  std::cout << prometheus << " Writing entropies ... " << std::endl;
  WriteSpeciesEntropies( out );

  std::cout << prometheus << " Writing Gibbs functions ... " << std::endl;
  WriteSpeciesGibbs( out );

  std::cout << prometheus << " Writing equilibrium constants ... " << std::endl;
  WriteEquilibriumConstants( out );

  std::cout << prometheus << " Writing Newton method for temperature inversion ... " << std::endl;
  WriteNewtonTemperature( out );
  
}

void Prometheus::WriteSpeciesSpecificHeats(std::ostream& out) {

  int    ncoeffGuess = 500;
  int    type;
  double minTemp;
  double maxTemp;
  double refPres;
  std::vector<double>  c(15);
  std::vector<double> c9(ncoeffGuess);
  //std::vector<double> c9(34);

  WriteFunctionName( out, "GasThermo", "" );
  
}

void Prometheus::WriteSpeciesEnthalpies(std::ostream& out) {
  
}

void Prometheus::WriteSpeciesEntropies(std::ostream& out) {
  
}

void Prometheus::WriteSpeciesGibbs(std::ostream& out) {
  
}

void Prometheus::WriteEquilibriumConstants(std::ostream& out) {
  
}

void Prometheus::WriteNewtonTemperature(std::ostream& out) {
  
}

void Prometheus::WriteKinetics(std::ostream& out) {

}

void Prometheus::WriteTransport(std::ostream& out) {

}

void Prometheus::WriteFunctionName(std::ostream& out,
				   const std::string& className,
				   const std::string& funName) {
  
}
