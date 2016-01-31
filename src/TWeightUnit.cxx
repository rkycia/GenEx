/***********************************************************************
*                        TWeightUnit                       
*                                                                           
* Returns dynamical part of weight corresponding to matrix element = 1.0.     
*		       
*   									       
***********************************************************************/

#include"TWeightUnit.h"


////////////////////////////////////////////////////////////////////////

const double TWeightUnit::PI =  M_PI;


////////////////////////////////////////////////////////////////////////
TWeightUnit::TWeightUnit()
{
  
	ConfigReader = ConfigReaderSubsystem::Instance();
	
	Logger = LoggerSubsystem::Instance();
	
	PDGDatabese = TDatabasePDG::Instance();
  
	ReadConfigFile( string("Generator.dat") );
 
  
}

TWeightUnit::~TWeightUnit(void)
{
	
};

////////////////////////////////////////////////////////////////////////
void TWeightUnit::ReadConfigFile( const string & filename )
{

	
	//Parse variables: setting up model variables	
	scalingFactor = ConfigReader->GetDoubleValue( "scalingFactor" );
	
	//Log configuration
	string ConfigLog = ConfigReader->GetStringValue( string("ConfigLogFile") );
	TLog * ConfigLogger = new TLog();
	ConfigLogger->setLogTime( false );
	ConfigLogger->openLogFile( ConfigLog );

	ConfigLogger->Write() << "# " << "-----------" << endl;
	ConfigLogger->Write() << "# " << "TWeightUnit" << endl;
	ConfigLogger->Write() << "# " << "-----------" << endl;
	
	ConfigLogger->Write() << "scalingFactor = " << scalingFactor << endl;

	delete ConfigLogger;
	
	return;
};

////////////////////////////////////////////////////////////////////////
double TWeightUnit::getAcceptance( TEvent * event )
{
    
       return( 1.0 );

};

////////////////////////////////////////////////////////////////////////
bool TWeightUnit::getIsAccepted( TEvent * event )
{
	bool isAccepted = true;
	
    return isAccepted;

};

////////////////////////////////////////////////////////////////////////
complex<double> TWeightUnit::getMatrixElement( TEvent * event )
{
	
	return( 1.0 );
	
};


////////////////////////////////////////////////////////////////////////
void TWeightUnit::SetEvent( TEvent * event, double eventWeight )
{
	
};

////////////////////////////////////////////////////////////////////////
double TWeightUnit::GetWeight( TEvent * event, double eventWeight )
{
	
	
	double weight = GetWeight( eventWeight );
	
	return( weight );
	
	
};

////////////////////////////////////////////////////////////////////////
double TWeightUnit::GetWeight( double eventWeight )
{
	double wt = eventWeight;

	//scale to GeV^-2 - no needed. One can imagine that the [ME]=GeV^{n-2}


	//scale by the user factor
	wt *= scalingFactor;

	double wtf = 1.0*wt;
	
	
	return wtf;
	
};
