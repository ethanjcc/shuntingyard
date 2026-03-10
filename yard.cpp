#include "yard.h"
#include <iostream>

using namespace std;

Node::Node(char value){
  data = value;
  next = nullptr;
}

//adds to the top of the array
void Node::push(Node *&top, char value) {
  Node *temp = new Node(value);
  temp->data = value;
  temp->next = top;
  top = temp;
}

//removes the newest value from the array
bool Node::pop(Node *&top, char &value) {
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
int Node::peek(Node* &top, char value) {
  if (!top) {
    return false;
    value = top->data;
    return true;
  }
}

//adds value to the back of the array
//help from copilot
void Node::enqueue(Node *&front, Node *&back, char value) {
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
bool Node::dequeue(Node *&front, Node *&back, char &value) {
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
    return 3;
  }
  if (op == '*' || op == '/') {
    return 2;
  }
  if (op == '+' || op == '-') {
    return 1;
  }
  return 0;
}

bool rtAssociative(char op) {
  return op == '^';
}
