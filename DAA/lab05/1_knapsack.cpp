#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item
{
      int value;
      int weight;
      double ratio; // Value-to-weight ratio
};

// Comparator to sort items by value-to-weight ratio in descending order
bool compare(Item a, Item b)
{
      return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item> &items, int n)
{
      int iterationCount = 0; // Iteration counter

      // Calculate value-to-weight ratio for each item
      for (int i = 0; i < n; i++)
      {
            items[i].ratio = (double)items[i].value / items[i].weight;
      }

      // Sort items by value-to-weight ratio in descending order
      sort(items.begin(), items.end(), compare);

      double totalValue = 0.0; // Total value in knapsack
      int currentWeight = 0;   // Current weight in knapsack

      // Fill the knapsack
      for (int i = 0; i < n; i++)
      {
            iterationCount++; // Increment iteration counter
            if (currentWeight + items[i].weight <= W)
            {
                  // Take the whole item
                  currentWeight += items[i].weight;
                  totalValue += items[i].value;
            }
            else
            {
                  // Take a fraction of the item
                  int remainingWeight = W - currentWeight;
                  totalValue += items[i].ratio * remainingWeight;
                  break;
            }
      }

      cout << "Total iterations: " << iterationCount << endl;
      return totalValue;
}

int main()
{
      vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
      int W = 50; // Knapsack capacity
      int n = items.size();

      cout << "Maximum value in fractional knapsack: " << fractionalKnapsack(W, items, n) << endl;

      return 0;
}
