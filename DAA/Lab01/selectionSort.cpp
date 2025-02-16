#include <iostream>
using namespace std;

void selectionSort(int array[], int length)
{
      for (int i = 0; i < length - 1; i++)
      {
            // Find the minimum element in the remaining unsorted array
            int minIndex = i;
            int smallest = array[i];
            for (int j = i + 1; j < length; j++)
            {
                  if (array[j] < smallest)
                  {
                        smallest = array[j];
                        minIndex = j;
                  }
            }

            // Swap the found minimum element with the ith position
            swap(array[i], array[minIndex]);
      }
}

int main()
{
      int array[] = {64, 25, 13, 88, 41, 70};
      int n = sizeof(array) / sizeof(array[0]);

      cout << "Original Array: ";
      for (int i = 0; i < n; i++)
      {
            cout << array[i] << " ";
      }
      cout << endl;

      selectionSort(array);

      cout << "\nSorted Array: ";
      for (int i = 0; i < n; i++)
      {
            cout << array[i] << " ";
      }
      cout << endl;

      return 0;
}
