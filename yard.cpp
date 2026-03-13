#include "yard.h"
#include <iostream>

using namespace std;

Node::Node(char value){
  data = value;
  next = nullptr;
}

//adds to the top of the array
void push(Node *&top, char value) {
  Node *temp = new Node(value);
  temp->data = value;
  temp->next = top;
  top = temp;
  //cout << "in push" << endl;
}

//removes the newest value from the array
bool pop(Node *&top, char &value) {
  if (!top) {
    return false;
  }
  Node *temp = top;
  value = top->data;
  top = top->next;
  delete temp;
  return true;
}

//looks at the top of the array without changing it
char peek(Node* &top, char value) {
  if (top != nullptr) {
    value = top->data;
    //cout << value << endl;
    return value;
  }
  return ' ';
}

//adds value to the back of the array
//help from copilot
void enqueue(Node *&front, Node *&back, char value) {
  Node *temp = new Node(value);
  //temp->data = value;
  //temp->next = nullptr;
  if (!front) {
    front = temp;
    back = temp;
  }
  else {
    back->next = temp;
    back = temp;
  }
}

//removes oldest value from the array
bool dequeue(Node *&front, Node *&back, char &value) {
  if (!front) {
    return false;
  }
  Node *temp = front;
  value = front->data;
  front = front->next;
  delete temp;
  if (!front) {
    back = nullptr;
  }
  return true;
}

bool isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
  if (op == '^') {
    cout << "^" << endl;
    return 3;
  }
  if (op == '*' || op == '/') {
    cout << "* or /" << endl;
    return 2;
  }
  if (op == '+' || op == '-') {
    cout << "+ or -" << endl;
    return 1;
  }
  cout << "hey" << endl;
  return 0;
}

bool rtAssociative(char op) {
  return op == '^';
}

void printTree(TreeNode* root, int depth) {
  if (root == nullptr) {
    return;
  }
  if (root->right != nullptr) {
    printTree(root->right, depth+1);
  }
  for (int a = 0; a < depth; a++) {
    cout << '\t';
  }
  cout << root->data << endl;
  if (root->left != nullptr) {
    printTree(root->left, depth + 1);
  }
}
void treeBuilder(TreeNode* right, TreeNode* left, Node* front, Node* back){
  TreeNode* treeStack = nullptr;
  char t = ' ';
  while (dequeue(front, back, t)) {
    if (isdigit(t)) {
      push(treeStack, new TreeNode(t));
    }
    else if (isOperator(t)) {
      TreeNode* right = treePop(treeStack);
      TreeNode* left = treePop(treeStack);
      TreeNode* op = new TreeNode(t);
      op->left = left;
      op->right = right;
      push(treeStack, op);
    }
  }
  TreeNode* root = pop(treeStack);
}

//adds to the top of the array
void treePush(TreeNode *&top, char treevalue) {
  TreeNode *temp = new Node(treevalue);
  temp->data = treevalue;
  temp->next = treetop;
  treetop = temp;
}

//removes the newest value from the array
bool treePop(TreeNode *&top, char &treevalue) {
  if (!treetop) {
    return false;
  }
  TreeNode *temp = treetop;
  treevalue = treetop->data;
  treetop = treetop->next;
  delete temp;
  return true;
}

//looks at the top of the array without changing it
char treePeek(TreeNode* &top, char treevalue) {
  if (treetop != nullptr) {
    treevalue = treetop->data;
    return treevalue;
  }
  return ' ';
}
