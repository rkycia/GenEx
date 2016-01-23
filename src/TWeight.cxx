/***********************************************************************
*                         TWeight                                 
*                                                                           
* Choice of matrix element (dynamic part of the event weight wgt_ME).  
*		       
*   									       
***********************************************************************/

#include"TWeight.h"


////////////////////////////////////////////////////////////////////////
TWeight::TWeight()
{
  
	ConfigReader = ConfigReaderSubsystem::Instance();
  
	ReadConfigFile( string("Generator.dat") );
 
 	Logger = LoggerSubsystem::Instance();
  
  
	switch( weightStrategy )
	{
							
		case( 1 ):  strategy = new TWeightLSpipi();
					break;
					
		case( 2 ):  strategy = new TWeightLSKK();
					break;	
					
		case( 3 ):  strategy = new TWeightUnit();
					break;

		case( 4 ): strategy = new TWeightGaussPt();
					break;								
					
		default:  cout << "TWeight :: NO SUCH STARTEGY" << endl;
				  throw( 0 );
				  break;
	}
   
}

TWeight::~TWeight(void)
{
	
	delete strategy;
  
};

////////////////////////////////////////////////////////////////////////
void TWeight::ReadConfigFile( const string & filename )
{

	//Parse variables: setting up model variables	

	weightStrategy = ConfigReader->GetIntValue( "weightStrategy" );
	
	//Log configuration
	string ConfigLog = ConfigReader->GetStringValue( string("ConfigLogFile") );
	TLog * ConfigLogger = new TLog();
	ConfigLogger->setLogTime( false );
	ConfigLogger->openLogFile( ConfigLog );

	ConfigLogger->Write() << "# " << "-----------" << endl;
	ConfigLogger->Write() << "# " << "TWeight " << endl;
	ConfigLogger->Write() << "# " << "-----------" << endl;
	ConfigLogger->Write() << "weightStrategy = " << weightStrategy << endl;
	
	delete ConfigLogger;
	
	
	return;
};

////////////////////////////////////////////////////////////////////////
bool TWeight::getIsAccepted( TEvent * event )
{
	return( strategy->getIsAccepted( event ) );
};

////////////////////////////////////////////////////////////////////////
double TWeight::getAcceptance( TEvent * event )
{
	
	return( strategy->getAcceptance( event ) );
	
};

////////////////////////////////////////////////////////////////////////
complex<double> TWeight::getMatrixElement( TEvent * event )
{
	return( strategy->getMatrixElement( event ) );	
	
};

////////////////////////////////////////////////////////////////////////
double TWeight::GetWeight( TEvent * event, double eventWeight )
{

	return( strategy->GetWeight( event, eventWeight ) );	

};
