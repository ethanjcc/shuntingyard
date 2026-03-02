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

//removes from the top of the array
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
  //value = top->data;
  return value;
}
