/***********************************************************************
*                         THistogram                               
*                                                                           
* Selects histogramming class depending on the number of particles in final state.                                             
*		       
*   									       
***********************************************************************/

#ifndef THistogram_H
#define THistogram_H

/*!
  @class THistogram

  @brief Selects histogramming class depending on the number of particles in final state.

 */


#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <complex>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <assert.h>

#include <TSystem.h>
#include <TROOT.h>
#include <TRandom.h>
#include <TApplication.h>
#include <TSystem.h>
#include <TFile.h>
#include <TObjArray.h>
#include <TLorentzVector.h>
#include <TParticlePDG.h>
#include <TDatabasePDG.h>

#include "Global.h"
#include "TConfigReader.h"
#include "TPolicyReader.h"
#include "TEvent.h"
#include "TWeightStrategy.h"
#include "THistogram3.h"
#include "THistogram4.h"
#include "THistogramN.h"


using namespace std;

////////////////////////////////////////////////////////////////////////
//#define DEBUG
////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////
class THistogram:  public THistogramStrategy 
{

private:
     
     ///weight
     THistogramStrategy * strategy;
     
	///configuration file reader
	TConfigReader * ConfigReader;

	///reads configuration form the file
	void ReadConfigFile( const string & filename );

	///Model used
	int eventGenerationStrategy;
   
    /// Logging
	TLog * Logger;
   
public:
    
    ///Constructor
    THistogram(void);                    
    
    ///Destructor
    virtual ~THistogram(void);           
  
  	/// Collect event
	/// @param event - event that contains an event
	/// @param weight - weight of event
	virtual void Fill( TEvent * event, double weight  );
	
	/// Set output file
	/// @param filename set the name of the output file
	virtual void SetOutputFile( const string & filename );
	
	///Save histograms into file
	///@param xsection cross-section, e.g., for differential cross-section histograms
	virtual void WriteHistograms(double xsection);


};
#endif
