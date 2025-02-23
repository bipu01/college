#include <iostream>
using namespace std;

// Global variable to count iterations
int iterationCount = 0;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i)
{
      iterationCount++; // Count each heapify call as an iteration

      int largest = i;       // Initialize largest as root
      int left = 2 * i + 1;  // Left child
      int right = 2 * i + 2; // Right child

      // Compare with left child
      if (left < n && arr[left] > arr[largest])
            largest = left;

      // Compare with right child
      if (right < n && arr[right] > arr[largest])
            largest = right;

      // If largest is not root
      if (largest != i)
      {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
      }
}

// Main HeapSort function
void heapSort(int arr[], int n)
{
      // Build max heap
      for (int i = n / 2 - 1; i >= 0; i--)
      {
            heapify(arr, n, i);
      }

      // Extract elements from heap one by one
      for (int i = n - 1; i > 0; i--)
      {
            swap(arr[0], arr[i]); // Move current root to end
            heapify(arr, i, 0);   // Call heapify on reduced heap
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
      heapSort(arr, n);

      cout << "Sorted array: ";
      printArray(arr, n);
      cout << "Number of iterations: " << iterationCount << endl;

      return 0;
}
