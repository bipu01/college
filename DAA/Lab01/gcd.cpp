#include <iostream>
using namespace std;

int iteration = 0;

int gcd(int a, int b)
{
      iteration++;

      if (b == 0)
      {
            return a;
      }
      else if (a % b == 0)
      {
            return b;
      }

      return gcd(b, a % b);
}

int main()
{
      cout << "Enter two numbers to find " << endl;
      int num1, num2;
      cout << "Num1: " << endl;
      cin >> num1;
      cout << "Num2: " << endl;
      cin >> num2;

      cout << "GCD is: " << gcd(num1, num2) << " and iterations: " << iteration << endl;
      return 0;
}
