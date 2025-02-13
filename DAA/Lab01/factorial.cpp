#include <iostream>
using namespace std;

int iteration = 0;

int fact(int n)
{
      iteration++;
      if (n == 1)
      {
            return n;
      }

      return n * fact(n - 1);
}

int main()
{
      cout << "Enter a number to find factorial:" << endl;
      int num;
      cin >> num;
      cout << "The factorial of " << num << " is: " << fact(num) << " and iteration is " << iteration << endl;
      return 0;
}
