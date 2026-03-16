#include "yard.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  Node* top = nullptr;
  Node *front = nullptr;
  Node *back = nullptr;
  char input[50];
  cout << "enter expression" << endl;
  cin.getline(input, 50);
  for (int i = 0; i < strlen(input); i++){
    char c = input[i];
    if (c == ' ') {
      continue;
    }
    else if (isdigit(c)) {
      enqueue(front, back, c);
    }
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
      while (top != nullptr && isOperator(top->data)) {
	char topOp = top->data;
	bool higher = precedence(topOp) > precedence(c);
	bool left = precedence(topOp) == precedence(c) && !rtAssociative(c);
	if (higher || left) {
	  char popped;
	  pop(top, popped);
	  enqueue(front, back, popped);
	}
	else {
	  break;
	}
      }
      push(top, c);
      
    }
    else if (c == '(') {
      push(top, c);
    }
    else if (c == ')') {
      //pop until it meets a "("
      char popped;
      while (top != nullptr && top->data != '(') {
	pop(top, popped);
	enqueue(front, back, popped);
      }
      if (top != nullptr && top->data == '(') {
	pop(top, popped);
      }
    }
  }
  char c = ' ';
  while (peek(top, c) != ' ') {
    char c;
    pop(top, c);
    enqueue(front, back, c);
  }
  cout << peek(top, c) << endl;
  cout << c << endl;
  TreeNode* root = treeBuilder(nullptr, nullptr, front, back);
    while (dequeue(front, back, c) != 0) {
      char uInput[50] = " ";
      int depth = 0;
      printTree(root, depth);
      cout << "prefix, infix, or postfix" << endl;
      cin >> uInput;
      if (strcmp(uInput, "prefix") == 0) {
	prefix(root);
      }
      else if (strcmp(uInput, "infix") == 0) {
        infix(root);
      }
      else if (strcmp(uInput, "postfix") == 0) {
	postfix(root);
      }
    }
}
  /*
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
  */
