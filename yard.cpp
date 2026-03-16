#include "yard.h"
#include <iostream>

using namespace std;

Node::Node(char value){
  data = value;
  next = nullptr;
}

TreeNode::TreeNode(char treevalue) {
  treedata = treevalue;
  left = nullptr;
  right = nullptr;
  treenext = nullptr;
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
int dequeue(Node *&front, Node *&back, char &value) {
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
  cout << root->treedata << endl;
  if (root->left != nullptr) {
    printTree(root->left, depth + 1);
  }
}
TreeNode* treeBuilder(TreeNode* right, TreeNode* left, Node* front, Node* back){
  TreeNode* treeStack = nullptr;
  char t = ' ';
  while (dequeue(front, back, t)) {
    if (isdigit(t)) {
      treePush(treeStack, t);
    }
    else if (isOperator(t)) {
      TreeNode* op = new TreeNode(t);
      TreeNode* right = treePop(treeStack, t);
      TreeNode* left = treePop(treeStack, t);
      op->left = left;
      op->right = right;
      treePush2(treeStack, op);
    }
  }
  return treePop(treeStack, t);
}

//adds to the top of the array (for tree builder)
void treePush(TreeNode *&treetop, char treevalue) {
  TreeNode *temp = new TreeNode(treevalue);
  temp->treedata = treevalue;
  temp->treenext = treetop;
  treetop = temp;
}

void treePush2(TreeNode *&top, TreeNode* &node){
  node->treenext = top;
  top = node;
}

//removes the newest value from the array (for tree builder)
TreeNode* treePop(TreeNode *&treetop, char &treevalue) {
  if (!treetop) {
    return nullptr;
  }
  TreeNode *temp = treetop;
  treevalue = treetop->treedata;
  treetop = treetop->treenext;
  return temp;
}

//looks at the top of the array without changing it (for tree builder)
char treePeek(TreeNode* &treetop, char treevalue) {
  if (treetop != nullptr) {
    treevalue = treetop->treedata;
    return treevalue;
  }
  return ' ';
}

void prefix(TreeNode* root) {
  if (root == nullptr){
    return;
  }
  cout << root->treedata << ' ';
  if (root->left != nullptr) {
    prefix(root->left);
  }
  if (root->right != nullptr) { 
    prefix(root->right);
  }
}

void infix(TreeNode* root) {
  if (left == nullptr) {
    return;
  }
  if (root->left != nullptr) {
    infix(root->left);
  }
  cout << root->treedata << ' ';
  if (root->right != nullptr) {
    infix(root->right);
  }
}

void postfix(TreeNode* root) {
  if (root == nullptr) {
    return;
  }
  if (root->left != nullptr) {
    postfix(root->left);
  }
  if (root->right != nullptr) {
    postfix(root->right);
  }
  cout << root->treedata << endl;
}
