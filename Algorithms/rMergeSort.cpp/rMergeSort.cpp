//Perform recursive Merge Sort on the array
void rMergeSort(int * x, long left, long right)
{
	//if 0 or 1 elements in subarray, stop
	if (left >= right) 
		return;
	//More than 2 elements in subarray, sort
	else 
	{	//compute middle
		long m =  left + (right - left) / 2;

		//sort 1st subarray and sort 2nd subarray
		rMergeSort(x, left, m);
		rMergeSort(x, m+1, right);

		//merge two sorted subarrays
		Merge(x, left, m, right);
	}
}

// merge 
void Merge(int * x, long left, long m, long right)
{
	//determine sizes of two sorted parts
	long n1 = m - left + 1;
	long n2 = right - m;

	// Dynamically allocate temp arrays for both subarrays
	int* L = new int[n1];
	int* R = new int[n2];

	//Copy data to temp arrays L[] and R[]
	for (long i = 0; i < n1; i++)
		L[i] = x[left + i];
	for (long j = 0; j < n2; j++)
		R[j] = x[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	
	long i = 0;		// Initial index of first subarray
	long j = 0;		// Initial index of second subarray
	long k = left;	// Initial index of merged subarray


	//while elements in both subarrays, merge
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			x[k] = L[i];
			i++;
		}
		else {
			x[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy remaining elements of L[], if there are any
	while (i < n1) {
		x[k] = L[i];
		i++;
		k++;
	}

	// Copy remaining elements of R[], if there are any
	while (j < n2) {
		x[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}
