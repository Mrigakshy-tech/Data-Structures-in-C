#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low = 0, mid, high = size - 1;
    // Keep searching until low <= high
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        // Searching ends
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,5,56,64,73,123,225,444};
    int size = sizeof(arr)/sizeof(int);
    int element = 0;
    int searchIndex = binarySearch(arr,size,element);
    printf("The element %d is found at index %d\n", element, searchIndex);
    return 0;
}