#include <iostream>
using namespace std;

class GameNode
{
private:
      int value;
      GameNode *children[10];
      int childCount;

public:
      // Constructor
      GameNode(int val = 0)
      {
            value = val;
            childCount = 0;
            for (int i = 0; i < 10; i++)
            {
                  children[i] = nullptr;
            }
      }

      // Method to add child node
      void addChild(GameNode *child)
      {
            if (childCount < 10)
            {
                  children[childCount++] = child;
            }
      }

      // Getter methods
      int getValue() const
      {
            return value;
      }

      int getChildCount() const
      {
            return childCount;
      }

      GameNode *getChild(int index) const
      {
            if (index < childCount)
            {
                  return children[index];
            }
            return nullptr;
      }
};

class MinimaxAlgorithm
{
private:
      const int INF_POS = 1000;
      const int INF_NEG = -1000;

      int minimax(GameNode *node, int depth, bool maximizingPlayer)
      {
            // Base case: leaf node or maximum depth reached
            if (depth == 0 || node->getChildCount() == 0)
            {
                  return node->getValue();
            }

            if (maximizingPlayer)
            {
                  int maxEval = INF_NEG;
                  for (int i = 0; i < node->getChildCount(); i++)
                  {
                        int eval = minimax(node->getChild(i), depth - 1, false);
                        maxEval = max(maxEval, eval);
                  }
                  return maxEval;
            }
            else
            {
                  int minEval = INF_POS;
                  for (int i = 0; i < node->getChildCount(); i++)
                  {
                        int eval = minimax(node->getChild(i), depth - 1, true);
                        minEval = min(minEval, eval);
                  }
                  return minEval;
            }
      }

public:
      int findOptimalMove(GameNode *root, int depth)
      {
            return minimax(root, depth, true);
      }
};

class GameTree
{
private:
      GameNode *root;

public:
      GameTree()
      {
            // Create leaf nodes with example values
            GameNode *leaf1 = new GameNode(3);
            GameNode *leaf2 = new GameNode(5);
            GameNode *leaf3 = new GameNode(2);
            GameNode *leaf4 = new GameNode(9);
            GameNode *leaf5 = new GameNode(12);
            GameNode *leaf6 = new GameNode(8);
            GameNode *leaf7 = new GameNode(4);
            GameNode *leaf8 = new GameNode(6);

            // Create internal nodes
            GameNode *internal1 = new GameNode();
            GameNode *internal2 = new GameNode();
            GameNode *internal3 = new GameNode();
            GameNode *internal4 = new GameNode();

            // Create root
            root = new GameNode();

            // Build the tree structure
            internal1->addChild(leaf1);
            internal1->addChild(leaf2);

            internal2->addChild(leaf3);
            internal2->addChild(leaf4);

            internal3->addChild(leaf5);
            internal3->addChild(leaf6);

            internal4->addChild(leaf7);
            internal4->addChild(leaf8);

            root->addChild(internal1);
            root->addChild(internal2);
            root->addChild(internal3);
            root->addChild(internal4);

            cout << "Game tree created successfully!" << endl;
      }

      GameNode *getRoot()
      {
            return root;
      }

      // Destructor to clean up memory
      ~GameTree()
      {
            deleteTree(root);
            cout << "Game tree deleted successfully!" << endl;
      }

private:
      void deleteTree(GameNode *node)
      {
            if (node != nullptr)
            {
                  for (int i = 0; i < node->getChildCount(); i++)
                  {
                        deleteTree(node->getChild(i));
                  }
                  delete node;
            }
      }
};

int main()
{
      cout << "Starting Minimax Algorithm Demo..." << endl;

      // Create game tree
      GameTree gameTree;

      // Create minimax algorithm instance
      MinimaxAlgorithm minimax;

      // Find optimal value
      int optimalValue = minimax.findOptimalMove(gameTree.getRoot(), 2);
      cout << "Optimal value found: " << optimalValue << endl;

      cout << "Demo completed successfully!" << endl;
      return 0;
}
