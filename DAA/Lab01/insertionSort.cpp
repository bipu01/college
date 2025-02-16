#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
      int iterationCount = 0; // Iteration counter

      for (int i = 1; i < n; i++)
      {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                  iterationCount++; // Increment iteration counter for each comparison
                  arr[j + 1] = arr[j];
                  j--;
            }
            arr[j + 1] = key;
      }

      cout << "Total iterations: " << iterationCount << endl;
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

      insertionSort(arr, n);

      cout << "Sorted array: ";
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
      cout << endl;

      return 0;
}
