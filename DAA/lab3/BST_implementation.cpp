#include <iostream>

// Node structure for BST
struct Node
{
      int data;
      Node *left;
      Node *right;

      Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
      Node *root;

      // Private helper functions
      Node *insertHelper(Node *node, int value)
      {
            if (node == nullptr)
            {
                  return new Node(value);
            }

            if (value < node->data)
            {
                  node->left = insertHelper(node->left, value);
            }
            else if (value > node->data)
            {
                  node->right = insertHelper(node->right, value);
            }

            return node;
      }

      Node *searchHelper(Node *node, int value)
      {
            if (node == nullptr || node->data == value)
            {
                  return node;
            }

            if (value < node->data)
            {
                  return searchHelper(node->left, value);
            }

            return searchHelper(node->right, value);
      }

      void inorderHelper(Node *node)
      {
            if (node == nullptr)
            {
                  return;
            }

            inorderHelper(node->left);
            std::cout << node->data << " ";
            inorderHelper(node->right);
      }

public:
      BinarySearchTree() : root(nullptr) {}

      // Insert a value into the BST
      void insert(int value)
      {
            root = insertHelper(root, value);
      }

      // Search for a value in the BST
      bool search(int value)
      {
            Node *result = searchHelper(root, value);
            return result != nullptr;
      }

      // Print the BST in-order
      void printInorder()
      {
            inorderHelper(root);
            std::cout << std::endl;
      }
};

// Example usage
int main()
{
      BinarySearchTree bst;

      // Insert some values
      bst.insert(50);
      bst.insert(30);
      bst.insert(70);
      bst.insert(20);
      bst.insert(40);
      bst.insert(60);
      bst.insert(80);

      std::cout << "BST In-order traversal: ";
      bst.printInorder();

      // Test search functionality
      int searchValue = 40;
      std::cout << "Searching for " << searchValue << ": ";
      if (bst.search(searchValue))
      {
            std::cout << "Found!" << std::endl;
      }
      else
      {
            std::cout << "Not found!" << std::endl;
      }

      searchValue = 90;
      std::cout << "Searching for " << searchValue << ": ";
      if (bst.search(searchValue))
      {
            std::cout << "Found!" << std::endl;
      }
      else
      {
            std::cout << "Not found!" << std::endl;
      }

      return 0;
}
