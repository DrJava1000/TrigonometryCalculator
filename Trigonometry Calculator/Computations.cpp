#include "stdafx.h"
#include "UnitConversions.h"
using namespace std; 

string UnitConversions::obtainUnknownSides(string knownSideLetter, double knownSideValue, string knownAngleLetter, double knownAngleValue)
{
	string angleSideCombo = knownAngleLetter + knownSideLetter; // combine known side and known angle letters for calculations to prevent the use of nested if statements 
	double firstUnknownSide = 0; // first calculated unknown 
	double secondUnknownSide = 0; // second calculated unknown 

	// angle x and side y calculations same as angle y and side x calculations 
	if (angleSideCombo.compare("xy") == 0 || angleSideCombo.compare("yx") == 0)
	{
		firstUnknownSide = tan(knownAngleValue) * knownSideValue;
		secondUnknownSide = knownSideValue / cos(knownAngleValue);
		if(angleSideCombo.compare("xy") == 0)
		 return "side x = " + to_string(firstUnknownSide) + ", side z = " + to_string(secondUnknownSide); // side y is known
		else
		 return "side y = " + to_string(firstUnknownSide) + ", side z = " + to_string(secondUnknownSide); // side x is known 
	}

	// angle x and side x calculations the same as angle y and side y calculations 
	if (angleSideCombo.compare("xx") == 0 || angleSideCombo.compare("yy") == 0)
	{
		firstUnknownSide = knownSideValue / tan(knownAngleValue);
		secondUnknownSide = knownSideValue / sin(knownAngleValue);
		if(angleSideCombo.compare("xx") == 0)
		 return "side y = " + to_string(firstUnknownSide) + ", side z = " + to_string(secondUnknownSide); // side x is known 
		else
		 return "side x = " + to_string(firstUnknownSide) + ", side z = " + to_string(secondUnknownSide); // side y is known 
	}

	// calculations here are looking for the same two sides with different angles
	// x and y side values with x can be switched to get the y and x side values with y
	if (angleSideCombo.compare("xz") == 0 || angleSideCombo.compare("yz") == 0)
	{
		firstUnknownSide = knownSideValue * sin(knownAngleValue);
		secondUnknownSide = knownSideValue * cos(knownAngleValue);
		if(angleSideCombo.compare("xz") == 0)
		 return "side x = " + to_string(firstUnknownSide) + ", side y = " + to_string(secondUnknownSide);
		else
		 return "side x = " + to_string(secondUnknownSide) + ", side y = " + to_string(firstUnknownSide);
	}

	return "";
}

string UnitConversions::obtainUnknownAngles(string firstSideLetter, double firstSideValue, string secondSideLetter, double secondSideValue)
{
	string sideCombo = firstSideLetter + secondSideLetter; // combine known side letters for calculations to prevent the use of nested if statements 
	double xAngle = 0; // angle x
	double yAngle = 0; // angle y 

	// angle x = tan^-1(x/y) angle y = tan^-1(y/x)
	if (sideCombo.compare("xy") == 0)
	{
		xAngle = radiansToDegrees(atan(firstSideValue / secondSideValue)); 
		yAngle = radiansToDegrees(atan(secondSideValue / firstSideValue)); 
		return "m<X = " + to_string(xAngle) + ", m<Y = " + to_string(yAngle); 
    }

	// reverse scenario input  
	if (sideCombo.compare("yx") == 0)
	{
		xAngle = radiansToDegrees(atan(secondSideValue / firstSideValue));
		yAngle = radiansToDegrees(atan(firstSideValue / secondSideValue));
		return "m<X = " + to_string(xAngle) + ", m<Y = " + to_string(yAngle);
	}

	// angle x = cos^-1(y/z) angle y = sin^-1(y/z)
	if (sideCombo.compare("yz") == 0)
	{
		xAngle = radiansToDegrees(acos(firstSideValue / secondSideValue));
		yAngle = radiansToDegrees(asin(firstSideValue / secondSideValue));
		return "m<X = " + to_string(xAngle) + ", m<Y = " + to_string(yAngle);
	}

	 // reverse input scenario 
	if (sideCombo.compare("zy") == 0)
	{
		xAngle = radiansToDegrees(acos(secondSideValue / firstSideValue));
		yAngle = radiansToDegrees(asin(secondSideValue / firstSideValue));
		return "m<X = " + to_string(xAngle) + ", m<Y = " + to_string(yAngle);
	}

	//angle x = sin^-1(x/z) = angle y = cos^-1(x/z)
	if (sideCombo.compare("xz") == 0)
	{
		xAngle = radiansToDegrees(asin(firstSideValue / secondSideValue));
		yAngle = radiansToDegrees(acos(firstSideValue / secondSideValue));
		return "m<X = " + to_string(xAngle) + ", m<Y = " + to_string(yAngle);
	}

	// reverse input scenario 
	if (sideCombo.compare("zx") == 0)
	{
		xAngle = radiansToDegrees(asin(secondSideValue / firstSideValue));
		yAngle = radiansToDegrees(acos(secondSideValue / firstSideValue));
		return "m<X = " + to_string(xAngle) + ", m<Y = " + to_string(yAngle);
	}
	return ""; 
}

// convert radians to degrees 
double UnitConversions::radiansToDegrees(double radians)
{
	return radians * (180 / 3.14);
}

// cpnvert degrees to radians 
double UnitConversions::degreesToRadians(double degrees)
{
	return degrees * (3.14 / 180);
}