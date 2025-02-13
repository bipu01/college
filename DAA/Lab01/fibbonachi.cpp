#include <iostream>
using namespace std;

int iteration = 0;

int fibb(int num)
{
      iteration++;

      if (num == 1)
      {
            return 0;
      }
      else if (num == 2)
      {
            return 1;
      }

      return fibb(num - 1) + fibb(num - 2);
}

int main()
{
      int inp;
      cout << "Enter a nth term of fibbonachi series: ";
      cin >> inp;
      cout << "\n\nThe " << inp << "th term of fibbonachi series is: " << fibb(inp) << "\nIteration is " << iteration << endl;
      return 0;
};
