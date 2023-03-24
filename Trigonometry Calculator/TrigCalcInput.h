#ifndef TRIG_CALCULATOR_H
#define TRIG_CALCULATOR_H
#include "UnitConversions.h"
using namespace std; 
class TrigCalculatorInput
{
 public:
	 static string tempForHeapStrings;
	 static double tempForHeapDoubles; 
	
	 static double *firstKnownSideValuePtr;
	 static string *firstKnownSideLetterPtr;
	
	 static double *secondKnownSideValuePtr;
	 static string *secondKnownSideLetterPtr;
	
	 static double *knownAngleValuePtr;
	 static string *knownAngleLetterPtr;
	
	 string takeAngleOperationInputs();
	 string takeSideOperationInputs(); 
	 
	 static void deallocateTrigInputMemory(); 

	 UnitConversions conversion;  
}; 
#endif 
