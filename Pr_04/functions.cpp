#include <iostream>
#include <iomanip> 
#include <ostream>
usingnamespace std; 


//**************************************************************************************************************//
//                                          function prototypes with commments                                  //
//**************************************************************************************************************//
// Purpose: recursive Binary Search Algorithm
// Recieves: none 
// Returns: none
void iMergeSort(int * x, long left, long right);
void rMergeSort(int * x, long left, long right);
void Merge(int * x, long left, long middle, long right);
void genValues();



//**************************************************************************************************************//
//                                                function definitions                                          //
//**************************************************************************************************************//
//Purpose: asks user for output file name and opens it 
//Receives: none
//Returns: none
void openFile ()
{
  char outFileName[40];
  // ask for output file name 
  cout <<"Enter the output file name: ";
  cin >> outFileName;
  outfile.open(outFileName);
}

//Purpose: Prints heading
//Receives: none
//Returns: none
void printPageHeading ()
{
  cout << "Harley Coxon" << "2433 Discrete Structures & Analysis\n" << "Program 04 - Algorithm Timing Comparisons" << endl; 
  // display table 
  // format 
  // doing this step last
}

// Purpose: prints table columns & format
// Receives: none
// Returns: none
void printColumnHeadings ()
{
  cout << "n" << endl; 
  // display table info using IOmanip to format
  // doing this step last!
} 


