int binarySearch(int arr[], int size, int key) {
    if (size <= 0)
        return -1;

    int mid = size / 2;

    // if found 
    if (arr[mid] == key)
        return mid;

    // Search left half
    if (key < arr[mid])
        return binarySearch(arr, mid, key);

    // Search right half
    int result = binarySearch(arr + mid + 1, size - mid - 1, key);

    if (result == -1)
        return -1;
    else
        return result + mid + 1;
}

