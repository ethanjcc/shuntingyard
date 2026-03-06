struct Node {
 public:
  int data;
  Node *next;
  Node(int value);
  void push(Node *&top, int value);
  bool pop(Node *&top, int value);
  int peek(Node *&top, int value);
  void enqueue(Node *&front, Node *back, int value);
  bool dequeue(Node *&front, Node *back, int value);
};
