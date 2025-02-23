#include <iostream>
using namespace std;

// Global variable to count iterations
int iterationCount = 0;

// Function to swap two elements
void swap(int &a, int &b)
{
      int temp = a;
      a = b;
      b = temp;
}

// Simple pseudo-random partition function without external random libraries
int pseudoRandomPartition(int arr[], int low, int high)
{
      // Use a simple calculation based on indices for pseudo-randomness
      int pseudoRandom = low + ((high + low) * (low + 1)) % (high - low + 1);

      // Swap pseudo-random element with the last element
      swap(arr[pseudoRandom], arr[high]);

      // Standard partition
      int pivot = arr[high];
      int i = (low - 1);

      for (int j = low; j <= high - 1; j++)
      {
            if (arr[j] <= pivot)
            {
                  i++;
                  swap(arr[i], arr[j]);
            }
      }
      swap(arr[i + 1], arr[high]);
      return (i + 1);
}

// Randomized QuickSort function
void randomizedQuickSort(int arr[], int low, int high)
{
      iterationCount++; // Increment counter for each recursive call

      if (low < high)
      {
            // Get partition index
            int pi = pseudoRandomPartition(arr, low, high);

            // Recursively sort elements before and after partition
            randomizedQuickSort(arr, low, pi - 1);
            randomizedQuickSort(arr, pi + 1, high);
      }
}

// Function to print the array
void printArray(int arr[], int size)
{
      for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
      cout << endl;
}

int main()
{
      int n;
      cout << "Enter the size of array: ";
      cin >> n;

      int arr[n];
      cout << "Enter " << n << " elements: ";
      for (int i = 0; i < n; i++)
      {
            cin >> arr[i];
      }

      cout << "Original array: ";
      printArray(arr, n);

      // Reset iteration count before sorting
      iterationCount = 0;
      randomizedQuickSort(arr, 0, n - 1);

      cout << "Sorted array: ";
      printArray(arr, n);
      cout << "Number of iterations: " << iterationCount << endl;

      return 0;
}
