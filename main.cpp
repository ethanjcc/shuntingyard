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
  //get expression from user input
  cout << "enter expression" << endl;
  cin.getline(input, 50);
  for (int i = 0; i < strlen(input); i++){
    char c = input[i];
    if (c == ' ') {
      continue;
    }
    //if its a digit put it in the back
    else if (isdigit(c)) {
      enqueue(front, back, c);
    }
    //if it is one of these operators use precidence to pop the top then put into the queue
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
    //push if it sees a (
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
  //build the tree from given expression
  TreeNode* root = treeBuilder(nullptr, nullptr, front, back);
    while (dequeue(front, back, c) != 0) {
      char uInput[50] = " ";
      int depth = 0;
      printTree(root, depth);
      //user input for either prefix infix or postfix
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
