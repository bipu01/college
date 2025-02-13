#include <iostream>
using namespace std;

class Object
{
public:
      int price;
      int weight;
      float proportion;

      float getInputAndFindProportion()
      {
            cout << "Enter the price of the object: ";
            cin >> price;

            cout << "Enter the weight of the object: ";
            cin >> weight;

            findProportion();
      }

      float findProportion()
      {
            proportion = price / weight;
            return proportion;
      }
};

int main()
{
      int maxBucketSize = 0;
      int n;
      cout << "How many objects do you want to enter: ";
      cin >> n;

      cout << "What is the max bucket size: ";
      cin >> maxBucketSize;

      Object obj[n];

      // Object propertionValues[n];
      float sortedKnapsackValues[n];

      for (int i = 0; i < n; i++)
      {
            obj[i].getInputAndFindProportion();
      }

      // Sorts the objects based on proportion values
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  if (obj[i].proportion > obj[j].proportion)
                  {
                        Object temp = obj[i];
                        obj[i] = obj[j];
                        obj[j] = temp;
                  }
            }
      }

      int usuableWeight = maxBucketSize;

      float maxKnapsackValue = 0;

      void findKnapsackValue()
      {
            int remainingSpace =
                for (int i = 0; i < n; i++)
            {
                  if (obj[i].weight <= usuableWeight)
                  {
                        usuableWeight -= obj[i].weight;

                        maxKnapsackValue += obj[i].price;
                  }
                  if (obj[i].weight >= usuableWeight)
                  {
                        usuableWeight =
                  }
            }
      }
      // for (int i = 0; i < n; i++)
      // {
      //       if (obj[i].proportion > maxKnapsackValue)
      //       {
      //             maxKnapsackValue = obj[i];
      //       }
      // }

      return 0;
}
