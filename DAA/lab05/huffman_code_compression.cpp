#include <iostream>
#include <vector>
using namespace std;

struct Node
{
      char ch;
      int freq;
      Node *left, *right;
      Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

void swap(Node *&a, Node *&b)
{
      Node *temp = a;
      a = b;
      b = temp;
}

void heapify(vector<Node *> &heap, int i, int size)
{
      int smallest = i;
      int left = 2 * i + 1;
      int right = 2 * i + 2;
      if (left < size && heap[left]->freq < heap[smallest]->freq)
            smallest = left;
      if (right < size && heap[right]->freq < heap[smallest]->freq)
            smallest = right;
      if (smallest != i)
      {
            swap(heap[i], heap[smallest]);
            heapify(heap, smallest, size);
      }
}

void insertHeap(vector<Node *> &heap, Node *node)
{
      heap.push_back(node);
      int i = heap.size() - 1;
      while (i > 0 && heap[(i - 1) / 2]->freq > heap[i]->freq)
      {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
      }
}

Node *extractMin(vector<Node *> &heap)
{
      Node *minNode = heap[0];
      heap[0] = heap.back();
      heap.pop_back();
      heapify(heap, 0, heap.size());
      return minNode;
}

void encode(Node *root, string str, vector<pair<char, string>> &huffmanCode)
{
      if (!root)
            return;
      if (!root->left && !root->right)
            huffmanCode.push_back({root->ch, str});
      encode(root->left, str + "0", huffmanCode);
      encode(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text)
{
      vector<pair<char, int>> freq;
      for (char ch : text)
      {
            bool found = false;
            for (auto &pair : freq)
            {
                  if (pair.first == ch)
                  {
                        pair.second++;
                        found = true;
                        break;
                  }
            }
            if (!found)
                  freq.push_back({ch, 1});
      }

      vector<Node *> heap;
      for (auto pair : freq)
            insertHeap(heap, new Node(pair.first, pair.second));

      while (heap.size() > 1)
      {
            Node *left = extractMin(heap);
            Node *right = extractMin(heap);
            Node *merged = new Node('\0', left->freq + right->freq);
            merged->left = left;
            merged->right = right;
            insertHeap(heap, merged);
      }

      vector<pair<char, string>> huffmanCode;
      encode(heap[0], "", huffmanCode);

      cout << "Huffman Codes:\n";
      for (auto pair : huffmanCode)
            cout << pair.first << " : " << pair.second << endl;
}

int main()
{
      string text = "huffman coding example";
      buildHuffmanTree(text);
      return 0;
}
