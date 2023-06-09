// Gambrell Trigonmetry Calculator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" 
#include "TrigCalcInput.h" 
using namespace std; 

void drawTrigDiagram();  

// Static variables from TrigCalculationsInput class in TrigCalcInput.h have to be redefined before use in this source file 
string TrigCalculatorInput::tempForHeapStrings; 
double TrigCalculatorInput::tempForHeapDoubles;

double * TrigCalculatorInput::firstKnownSideValuePtr;
string * TrigCalculatorInput::firstKnownSideLetterPtr;

double * TrigCalculatorInput::secondKnownSideValuePtr;
string * TrigCalculatorInput::secondKnownSideLetterPtr;

double * TrigCalculatorInput::knownAngleValuePtr;
string * TrigCalculatorInput::knownAngleLetterPtr;

TrigCalculatorInput input;

int main()
{
	string operationType;  

	cout << "\t\t\t\t\tTrigonmetry Calculator" << endl; 
	
	drawTrigDiagram(); 

	cout << "\nNote: Angle letters are the same as opposing sides." << endl;

	while (true)
	{
		cout << "\nAre you looking for a side or an angle? (s or a)" << endl;
		cin >> operationType;
		bool inputErr = true;
		int operation = 0;
		while (inputErr)
		{
			if (operationType.compare("s") == 0)
			{
				inputErr = false;
				operation = 1;
			}
			else
			{
				if (operationType.compare("a") == 0)
				{
					inputErr = false;
					operation = 2;
				}
				else
				{
					cout << "Try Again!" << endl;
					cout << "Side or Angle? (s or a)" << endl;
					cin >> operationType;
				}
			}
		}

		if (operation == 1)
		{
			cout << "\nThe missing side values: " << input.takeSideOperationInputs() << endl;
		}
		if (operation == 2)
		{
			cout << "\nThe missing angle values: " << input.takeAngleOperationInputs() << endl;
		}

		string continueComputations; 
		cout << "\nDo you want to do another trig calculation? (yes/no)" << endl; 
		cin >> continueComputations; 

		if(!(continueComputations.compare("yes") == 0 || continueComputations.compare("Yes") == 0))
		{
			break; // program exits loop and finishes execution if any answer other than Yes or yes is given 
		}

	}
}

void drawTrigDiagram()
{
 cout << "\t\t   |\\" << endl; 
 cout << "\t\t   | \\" << endl;
 cout << "\t\t x |  \\ z" << endl;
 cout << "\t\t   |   \\" << endl;
 cout << "\t\t   |    \\" << endl;
 cout << "\t\t      y" << endl; 
}

// for operation input functions, recycled pointers in TrigCalculatorInput class point to newly allocated heap memory for each datatype 
string TrigCalculatorInput::takeSideOperationInputs()
{
	cout << "\nWhich side do you know? (x, y, z)" << endl; 
	cin >> tempForHeapStrings; 
	firstKnownSideLetterPtr = new string(tempForHeapStrings); 
	cout << "  What is that side's value: "; 
	cin >> tempForHeapDoubles; 
	firstKnownSideValuePtr = new double(tempForHeapDoubles); 

	cout << "\nWhich angle do you know? (x / y)" << endl; 
	cin >> tempForHeapStrings; 
	knownAngleLetterPtr = new string(tempForHeapStrings); 
	cout << "  What is that angle's value? "; 
	cin >> tempForHeapDoubles; 
	tempForHeapDoubles = conversion.degreesToRadians(tempForHeapDoubles); // degree value fron user is translated into radians for program use 
	knownAngleValuePtr = new double(tempForHeapDoubles); 
	
	string sideOperationResult = conversion.obtainUnknownSides(*firstKnownSideLetterPtr, *firstKnownSideValuePtr, *knownAngleLetterPtr, *knownAngleValuePtr); 
	TrigCalculatorInput::deallocateTrigInputMemory(); 
	return sideOperationResult; 
}

string TrigCalculatorInput::takeAngleOperationInputs()
{
	cout << "\nEnter the first side (x, y, z): "; 
	cin >> tempForHeapStrings; 
	firstKnownSideLetterPtr = new string(tempForHeapStrings);
	cout << "\n  What is that side's value? ";
	cin >> tempForHeapDoubles; 
	firstKnownSideValuePtr = new double(tempForHeapDoubles);

	cout << "\nEnter the second side (x, y, z): ";
	cin >> tempForHeapStrings; 
	secondKnownSideLetterPtr = new string(tempForHeapStrings);
	cout << "\n  What is that side's value? ";
	cin >> tempForHeapDoubles; 
	secondKnownSideValuePtr = new double(tempForHeapDoubles);
	
	string angleOperationResult = conversion.obtainUnknownAngles(*firstKnownSideLetterPtr, *firstKnownSideValuePtr, *secondKnownSideLetterPtr, *secondKnownSideValuePtr);
	TrigCalculatorInput::deallocateTrigInputMemory();
	return angleOperationResult; 
}

// cleans up TrigCalculatorInput pointers to prevent a memory leak during extended program use 
void TrigCalculatorInput::deallocateTrigInputMemory()
{
	delete firstKnownSideValuePtr;
	firstKnownSideValuePtr = nullptr; 
	delete firstKnownSideLetterPtr;
	firstKnownSideLetterPtr = nullptr;

	delete secondKnownSideValuePtr;
	secondKnownSideValuePtr = nullptr; 
	delete secondKnownSideLetterPtr;
	secondKnownSideLetterPtr = nullptr; 

	delete knownAngleValuePtr;
	knownAngleValuePtr = nullptr; 
	delete knownAngleLetterPtr;
	knownAngleLetterPtr = nullptr; 
}


