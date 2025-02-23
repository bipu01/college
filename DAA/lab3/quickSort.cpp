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

// Partition function that returns the pivot position
int partition(int arr[], int low, int high)
{
      int pivot = arr[high]; // Taking the last element as pivot
      int i = (low - 1);     // Index of smaller element

      for (int j = low; j <= high - 1; j++)
      {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot)
            {
                  i++; // Increment index of smaller element
                  swap(arr[i], arr[j]);
            }
      }
      swap(arr[i + 1], arr[high]);
      return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high)
{
      iterationCount++; // Increment counter for each recursive call

      if (low < high)
      {
            // pi is partitioning index
            int pi = partition(arr, low, high);

            // Separately sort elements before and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
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
      quickSort(arr, 0, n - 1);

      cout << "Sorted array: ";
      printArray(arr, n);
      cout << "Number of iterations: " << iterationCount << endl;

      return 0;
}
