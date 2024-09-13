#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the pivot element
    int i = low;           // Start i at the low end
    int j = high;          // Start j at the high end

    while (i < j) {
        // Move i to the right while arr[i] is less than the pivot
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        // Move j to the left while arr[j] is greater than the pivot
        while (arr[j] > pivot && j > low) {
            j--;  
        }
        // If i is still less than j, swap the elements at i and j
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap the pivot element with the element at index j
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
