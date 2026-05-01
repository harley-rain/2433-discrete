//Perform iterative Merge Sort on the array
void iMergeSort(int * x, long left, long right)
{
	long k;							//index in original array
	long m = (left + right) / 2;	//index of middle
	long n1 = m - left + 1;			//number of elements in 1st subarray
	long n2 = right - m;			//number of elements in 2nd subarray

	//Dynamically allocate arrays for 1st and 2nd halves
	int* L = new int[n1];
	int* R = new int[n2];

	//Copy elements from original array to temp subarrays L[] and R[]
	for (long i = 0; i < n1; i++)
		L[i] = x[left + i];
	for (long j = 0; j < n2; j++)
		R[j] = x[m + 1 + j];

	// Merge the temp arrays back into arr[left..right]

	int i = 0;  // Initial index of first subarray
	int j = 0;  // Initial index of second subarray
	k = left;	// Initial index of merged subarray

	//while more elements in both subarrays
	while (i < n1 && j < n2)
	{
		//if element in 1st subarray is <= element in 2nd, store in original array
		if (L[i] <= R[j])
		{
			x[k] = L[i];
			i++;
		}
		//if element in 2nd subarray is <= element in 1st, store in original array
		else
		{
			x[k] = R[j];
			j++;
		}

		//increment location in original array
		k++;
	}

	// Copy the remaining elements of L[], if there are any
	while (i < n1)
	{
		x[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[], if there are any
	while (j < n2)
	{
		x[k] = R[j];
		j++;
		k++;
	}

	//delete dynamically allocated arrays
	delete[] L;
	delete[] R;
}