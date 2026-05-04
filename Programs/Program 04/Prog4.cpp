/*
Harley Coxon
CMPS 2433 - Dr. C. Stringfellow
Program 04 - algorithm timings
Description: this program compares iterative and recursive merge sort
and binary search algorithms by timing their execution
on arrays of increasing sizes. results are written to an outfile
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <time.h>
#include <cmath>
#include <string>
using namespace std;

// global constant max int size for arrays
const int MAXSIZES = 5;

// recieves: outFile reference
// returns: none
// purpose: prints program heading to output file
void printPageHeading(ofstream &outFile);

// recieves: outFile reference
// returns: none
// purpose: prints column headings to output file
void printColumnHeadings(ofstream &outFile);

// recieves: pointer to array and size n
// returns: none
// purpose: fills array with random values
void genValues(int *x, long n);

// recieves: value to search for, array, and size
// returns: index of value or -1 if not found
// purpose: performs iterative binary search
int iBinSearch(int x, int a[], int size);

// recieves: array, size, and key value
// returns: index of value or -1 if not found
// purpose: performs recursive binary search
int rBinSearch(int arr[], int size, int key);

// recieves: array and left/right indices
// returns: none
// purpose: sorts array using iterative merge sort structure
void iMergeSort(int * x, long left, long right);

// recieves: array and left/right indices
// returns: none
// purpose: sorts array using recursive merge sort
void rMergeSort(int * x, long left, long right);

// recieves: array and indices for left, middle, and right
// returns: none
// purpose: merges two sorted halves of an array
void Merge(int * x, long left, long m, long right);


// ---------------- MAIN ----------------
int main()
{
    using Clock = chrono::high_resolution_clock;

    int sizes[MAXSIZES] = {100, 1000, 10000, 100000, 1000000};

    long long start, stop;

    srand(time(NULL));

    ofstream outFile;
    string filename;

    cout << "enter output filename: ";
    cin >> filename;

    outFile.open(filename);

    outFile << fixed << setprecision(0);

    printPageHeading(outFile);
    printColumnHeadings(outFile);

    for (int i = 0; i < MAXSIZES; i++)
    {
        long n = sizes[i];

        int* x = new int[n];
        int* y = new int[n];

        genValues(x, n);

        for (long j = 0; j < n; j++)
            y[j] = x[j];
            
        long long iMergeTime, rMergeTime, iBinTime, rBinTime;

        start = Clock::now().time_since_epoch().count();
        iMergeSort(x, 0, n - 1);
        stop = Clock::now().time_since_epoch().count();
        iMergeTime = stop - start;

        start = Clock::now().time_since_epoch().count();
        rMergeSort(y, 0, n - 1);
        stop = Clock::now().time_since_epoch().count();
        rMergeTime = stop - start;

        int key = 13;

        start = Clock::now().time_since_epoch().count();
        iBinSearch(key, x, n);
        stop = Clock::now().time_since_epoch().count();
        iBinTime = stop - start;

        start = Clock::now().time_since_epoch().count();
        rBinSearch(x, n, key);
        stop = Clock::now().time_since_epoch().count();
        rBinTime = stop - start;

        outFile << setw(10) << n << setw(10) << (long)log2(n) << setw(12) << iBinTime << setw(12) << rBinTime << setw(15) << (long long)(n * log2(n)) << setw(15) << iMergeTime << setw(15) << rMergeTime << endl;

        delete[] x;
        delete[] y;
    }

    outFile.close();

    cout << "done. output written to file.\n";

    return 0;
}
// end main



// recieves: outFile reference
// returns: none
// purpose: prints program heading to output file
void printPageHeading(ofstream &outFile)
{
    outFile << "Harley Coxon\n";
    outFile << "Program 04: Algorithm Timings\n\n";
    outFile << "2433 Discrete Strutures - Dr Catherine Stringfellow\n\n";
}


// recieves: outFile ref
// returns: none
// purpose: prints column headings to output file
void printColumnHeadings(ofstream &outFile)
{
    outFile << setw(10) << "n"
            << setw(10) << "log2 n"
            << setw(12) << "iBin"
            << setw(12) << "rBin"
            << setw(15) << "nlog2n"
            << setw(15) << "iMerge"
            << setw(15) << "rMerge"
            << endl;

    outFile << string(100, '-') << endl;
}


// recieves: pointer to array and size n
// returns: none
// purpose: fills array with random values
void genValues(int *x, long n)
{
    for (long i = 0; i < n; i++)
        x[i] = rand();
}


// recieves: value to search for, array, and size
// returns: index of value or -1 if not found
// purpose: performs iterative binary search
int iBinSearch(int x, int a[], int size)
{
    int i = 0, j = size - 1, m, location;

    while (i < j)
    {
        m = (i + j) / 2;

        if (x > a[m])
            i = m + 1;
        else
            j = m;
    }

    if (x == a[i])
        location = i;
    else
        location = -1;

    return location;
}


// recieves: array, size, and key value
// returns: index of value or -1 if not found
// purpose: performs recursive binary search
int rBinSearch(int arr[], int size, int key)
{
    if (size <= 0)
        return -1;

    int mid = size / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return rBinSearch(arr, mid, key);

    int result = rBinSearch(arr + mid + 1, size - mid - 1, key);

    if (result == -1)
        return -1;
    else
        return result + mid + 1;
}


// recieves: array and left/right indices
// returns: none
// purpose: sorts array using recursive merge sort
void rMergeSort(int * x, long left, long right)
{
    if (left >= right)
        return;

    long m = left + (right - left) / 2;

    rMergeSort(x, left, m);
    rMergeSort(x, m + 1, right);

    Merge(x, left, m, right);
}


// recieves: array and indices for left, middle, and right
// returns: none
// purpose: merges two sorted halves of an array
void Merge(int * x, long left, long m, long right)
{
    long n1 = m - left + 1;
    long n2 = right - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (long i = 0; i < n1; i++)
        L[i] = x[left + i];
    for (long j = 0; j < n2; j++)
        R[j] = x[m + 1 + j];

    long i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            x[k++] = L[i++];
        else
            x[k++] = R[j++];
    }

    while (i < n1)
        x[k++] = L[i++];

    while (j < n2)
        x[k++] = R[j++];

    delete[] L;
    delete[] R;
}


// recieves: array and left/right indices
// returns: none
// purpose: sorts array using iterative merge sort structure
void iMergeSort(int * x, long left, long right)
{
    if (left >= right) return;

    long m = (left + right) / 2;

    iMergeSort(x, left, m);
    iMergeSort(x, m + 1, right);

    Merge(x, left, m, right);
}