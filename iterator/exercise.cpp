#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

template <typename T>
struct Node
{
  T value;
  Node *left{nullptr}, *right{nullptr}, *parent{nullptr};

  Node(T value) : value(value) {}

  Node(T value, Node<T> *left, Node<T> *right) : value(value), left(left), right(right)
  {
    left->parent = right->parent = this;
  }

  // traverse the node and its children preorder
  // and put all the results into `result`
  void preorder_traversal(vector<Node<T> *> &result)
  {
    result.push_back(this);
    if (left) left->preorder_traversal(result);
    if (right) right->preorder_traversal(result);
  }
};

int main()
{
  //         a
  //        /  \
    //       b    e
  //      / \
    //     c   d
  Node<char> c{'c'};
  Node<char> d{'d'};
  Node<char> e{'e'};
  Node<char> b{'b', &c, &d};
  Node<char> a{'a', &b, &e};

  vector<Node<char> *> result;
  a.preorder_traversal(result);

  ostringstream oss;
  for (auto n : result) oss << n->value;
  cout << oss.str() << endl;
}