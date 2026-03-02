#include "yard.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  Node* top = nullptr;
  top->push(top, 10);
  top->push(top, 20);
  top->push(top, 30);
  int x;
  top->peek(top, x);
  top->pop(top, x);
  top->pop(top, x);
  return 0;
}
