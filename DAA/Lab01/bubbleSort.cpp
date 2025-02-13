#include <iostream>
using namespace std;

int iteration = 0;
void bubbleSort(int arr[])
{
      iteration++;
      for (int i = 0; i < 5; i++)
      {
            for (int j = 0; j < 5 - i; j++)
            {
                  if (arr[j] > arr[j + 1])
                  {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                  }
            }
      }
}

int main()
{

      int arr[5];
      cout << "Enter 5 numbers: " << endl;
      for (int i = 0; i < 5; i++)
      {
            cin >> arr[i];
      }

      cout << "Sorted array: " << endl;
      bubbleSort(arr);
      for (int i = 0; i < 5; i++)
      {
            cout << arr[i] << " ";
      }

      return 0;
};
