struct Node {
 public:
  char data;
  Node *next;
  Node(char value);
  void push(Node *&top, char value);
  bool pop(Node *&top, char &value);
  int peek(Node *&top, char value);
  void enqueue(Node *&front, Node *&back, char value);
  bool dequeue(Node *&front, Node *&back, char &value);
  bool isOperator(char c);
  int precedence(char op);
  bool rtAssociative(char op);
};
