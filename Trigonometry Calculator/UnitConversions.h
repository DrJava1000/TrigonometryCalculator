#ifndef UNIT_CONVERSIONS_H
#define UNIT_CONVERSIONS_H
#include <iostream>
#include <string>
#include <cmath>

using namespace std; 
class UnitConversions
{
 public:
	 double radiansToDegrees(double radians); 
	 double degreesToRadians(double degrees); 
	 string obtainUnknownSides(string knownSideLetter, double knownSideValue, string knownAngleLetter, double knownAngleValue); 
	 string obtainUnknownAngles(string firstSideLetter, double firstSideValue, string secondSideLetter, double secondSideValue);
};
#endif
