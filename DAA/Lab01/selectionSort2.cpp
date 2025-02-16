#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
      int iterationCount = 0; // Counter to track the number of iterations

      for (int i = 0; i < n - 1; i++)
      {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                  iterationCount++; // Increment the iteration counter
                  if (arr[j] < arr[minIndex])
                  {
                        minIndex = j;
                  }
            }
            // Swap the found minimum element with the first element
            if (minIndex != i)
            {
                  swap(arr[i], arr[minIndex]);
            }
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

      selectionSort(arr, n);

      cout << "Sorted array: ";
      for (int i = 0; i < n; i++)
      {
            cout << arr[i] << " ";
      }
      cout << endl;

      return 0;
}
