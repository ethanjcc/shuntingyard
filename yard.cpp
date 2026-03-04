#include "yard.h"
#include <iostream>

using namespace std;

Node::Node(int value){

}

//adds to the top of the array
void Node::push(Node *&top, int value) {
  Node *temp = new Node(value);
  temp->data = value;
  temp->next = top;
  top = temp;
}

//removes the newest value from the array
bool Node::pop(Node *&top, int value) {
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
int Node::peek(Node* &top, int value) {
  if (!top) {
    return false;
  }
  return value;
}

//adds value to the back of the array
//help from copilot
void Node::enqueue(Node *&front, Node *back, int value) {
  Node *temp = new Node(value);
  temp->data = value;
  temp->next = nullptr;
  cout << "1" << endl;
  if (!front) {
    front = temp;
    back = temp;
  }
  else {
    back->next = temp;
    back = temp;
  }
  cout << "2" << endl;
}

//removes oldest value from the array
bool Node::dequeue(Node *&front, Node *back, int value) {
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
