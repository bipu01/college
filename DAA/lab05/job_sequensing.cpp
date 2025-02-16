#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a job
struct Job
{
      int id;
      int deadline;
      int profit;
};

// Comparator to sort jobs by profit in descending order
bool compare(Job a, Job b)
{
      return a.profit > b.profit;
}

void jobSequencing(vector<Job> &jobs, int n)
{
      int iterationCount = 0; // Iteration counter

      // Sort jobs by profit in descending order
      sort(jobs.begin(), jobs.end(), compare);

      vector<int> result(n, -1);   // To store the result (schedule)
      vector<bool> slot(n, false); // To track available slots

      // Fill the slots
      for (int i = 0; i < n; i++)
      {
            iterationCount++; // Increment iteration counter
            for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--)
            {
                  if (!slot[j])
                  {
                        result[j] = i;
                        slot[j] = true;
                        break;
                  }
            }
      }

      // Calculate total profit
      int totalProfit = 0;
      for (int i = 0; i < n; i++)
      {
            if (result[i] != -1)
            {
                  totalProfit += jobs[result[i]].profit;
            }
      }

      cout << "Total iterations: " << iterationCount << endl;
      cout << "Maximum profit: " << totalProfit << endl;
}

int main()
{
      vector<Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
      int n = jobs.size();

      jobSequencing(jobs, n);

      return 0;
}
