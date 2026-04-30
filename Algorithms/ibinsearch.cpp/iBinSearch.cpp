#include <iostream> 
using namespace std; 

// Recieves: x: int value to search for
// a[]: array of ints must be sorted 
// size: size of a[] arrray 
// Returns: location of x if found 
// Purpose: Searches through an array for int x 

int iBinSearch(int x, int a[], int size) 
{
    int i = 0; // start of array
    int j = size - 1; // end
    int m;  // midpoint
    int location; 

    while (i < j) 
    {
        // find midpoint uses integer division
        m = (i + j) / 2;  
        // if value (x) > current 
        // continue 
        if (x > a[m]) 
            i = m + 1; 
        // 
        else
            j = m;
    }
    
    // check if value is == current 
    if (x == a[i])
        location = i;
    else
        location = -1;

    // returns -1 if x not found 
    return location;

}

int main()
{
    // Testing the function :))))
    
    int arrayOne[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // size 10
    int arrayTwo[] = {0, 6, 9, 10, 19, 100}; // size 6
    int arrayThree[] = {9, 11, 30, 59, 100, 200, 300}; // size 7
    int arrayFour[] = {0, 6, 10, 19}; // size 4

    int find = 9; 
    
    cout << iBinSearch(find, arrayOne, 11) << endl;
    cout << iBinSearch(find, arrayTwo, 6) << endl;
    cout << iBinSearch(find, arrayThree, 7) << endl;
    cout << iBinSearch(find, arrayFour, 4) << endl;
}
   
