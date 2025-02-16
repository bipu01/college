#include <iostream>
using namespace std;

int iterationCount = 0;

int partition(int arr[], int low, int high)
{
      int pivot = arr[high]; // Pivot element
      int i = low - 1;       // Index of smaller element

      for (int j = low; j < high; j++)
      {
            iterationCount++; // Increment iteration counter for each comparison
            if (arr[j] < pivot)
            {
                  i++;
                  swap(arr[i], arr[j]);
            }
      }
      swap(arr[i + 1], arr[high]); // Place pivot in correct position
      return i + 1;                // Return partition index
}

void quickSort(int arr[], int low, int high)
{
      if (low < high)
      {
            int pi = partition(arr, low, high); // Partitioning index
            quickSort(arr, low, pi - 1);        // Sort left subarray
            quickSort(arr, pi + 1, high);       // Sort right subarray
      }
}

int main()
{
      int arr[] = {64, 25, 12, 22, 11};
      int n = sizeof(arr) / sizeof(arr[0]);

      cout << "Original array: ";
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
      cout << endl;

      quickSort(arr, 0, n - 1);

      cout << "Sorted array: ";
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
      cout << endl;

      cout << "Total iterations: " << iterationCount << endl;

      return 0;
}
