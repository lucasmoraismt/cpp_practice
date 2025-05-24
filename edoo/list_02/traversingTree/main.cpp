#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct BSTNode {
  int data;
  BSTNode* left;
  BSTNode* right;

  BSTNode(int value) : data(value), left(nullptr), right(nullptr) { }
};

class BST {
private:
  BSTNode* root;

  void insert(BSTNode*& node, int value) {
    if (node == nullptr) {
        node = new BSTNode(value);
    } else {
      if (value < node->data)
        insert(node->left, value);
      else
        insert(node->right, value);
    }
  }

  void preOrder(BSTNode* node, ostream &out) {
    if (node == nullptr)
      return;
    out << " " << node->data;
    preOrder(node->left, out);
    preOrder(node->right, out);
  }

  void inOrder(BSTNode* node, ostream &out) {
    if (node == nullptr)
      return;
    inOrder(node->left, out);
    out << " " << node->data;
    inOrder(node->right, out);
  }

  void postOrder(BSTNode* node, ostream &out) {
    if (node == nullptr)
      return;
    postOrder(node->left, out);
    postOrder(node->right, out);
    out << " " << node->data;
  }

  void destroyTree(BSTNode* node) {
    if (node == nullptr)
      return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }

public:
  BST() : root(nullptr) { }

  ~BST() {
    destroyTree(root);
  }

  void insert(int value) {
    insert(root, value);
  }

  void printPreOrder(ostream &out) {
    out << "Pre order :";
    preOrder(root, out);
    out << "\n";
  }

  void printInOrder(ostream &out) {
    out << "In order  :";
    inOrder(root, out);
    out << "\n";
  }

  void printPostOrder(ostream &out) {
    out << "Post order:";
    postOrder(root, out);
    out << "\n";
  }
};

int main(){
  int n;
  cin >> n;

  BST tree;

  for (int i = 0; i < n; i++){
    int value;
    cin >> value;
    tree.insert(value);
  }

  tree.printPreOrder(cout);
  tree.printInOrder(cout);
  tree.printPostOrder(cout);

  return 0;
}
