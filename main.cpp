#include "yard.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  Node* top = nullptr;
  char input[50];
  cout << "enter expression" << endl;
  char.getline(input, 50);
  for (int i = 0; i < strlen(expr); i++){
    char c = input[i];
    if (c == " ") {
      continue;
    }
    else if (isdigit(c)) {
      //enqueue
    }
    else if (c == "+" || c == "-" || c == "*" || c == "/" || c == "^") {
      //precidence
    }
    else if (c == "(") {
      //push
    }
    else if (c == ")") {
      //pop until it meets a "("
    }
  }
  if (strcmp(input, "STACK") == 0){
    top->push(top, 10);
    top->push(top, 20);
    top->push(top, 30);
    int x;
    if (top->peek(top, x)) {
      cout << "top of stack: " << x << endl;
    }
    while (top->pop(top, x)) {
      cout << "popped: " << x << endl;
    }
    if (!top->pop(top, x)) {
      cout << "stack is empty" << endl;
    }
    return 0;
  }
  else if (strcmp(input, "QUEUE") == 0) {
    Node *front = nullptr;
    Node *back = nullptr;
    front->enqueue(front, back, 10);
    front->enqueue(front, back, 20);
    front->enqueue(front, back, 30);
    int x;
    if (top->peek(top, x)) {
      cout << "front of queue: " << x << endl;
    }
    while (front->dequeue(front, back, x)) {
      cout << "dequeued: " << x << endl;
    }
    if (!front->dequeue(front, back, x)) {
      cout << "queue is empty" << endl;
    }
    return 0;
  }
}
