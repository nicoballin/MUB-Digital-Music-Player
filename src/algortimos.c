#include "algoritmos.h"

int binarySearch (int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    else 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch (arr, low, mid - 1, x);
        else
            return binarySearch (arr, mid + 1,high, x);
    }
}
