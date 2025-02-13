#include <iostream>
using namespace std;

class Job
{
public:
      string name;
      int profit;
      int deadline;

      Job(string n, int p, int d)
      {
            name = n;
            profit = p;
            deadline = d;
      }
      Job()
      {
      }
};

int main()
{
      Job Jobs[4] = {
          Job("j1", 50, 2),
          Job("j2", 15, 1),
          Job("j3", 10, 2),
          Job("j4", 25, 1)};

      return 0;
};
