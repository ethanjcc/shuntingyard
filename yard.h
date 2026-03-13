struct Node {
 public:
  char data;
  Node *next;
  Node(char value);
};

void push(Node *&top, char value);
bool pop(Node *&top, char &value);
char peek(Node *&top, char value);

void enqueue(Node *&front, Node *&back, char value);
bool dequeue(Node *&front, Node *&back, char &value);

bool isOperator(char c);
int precedence(char op);
bool rtAssociative(char op);

//help from copilot to get treenode struct
struct TreeNode {
  char data;
  TreeNode* left;
  TreeNode* right;
  TreeNode(char v) : data(v), left(nullptr), right(nullptr){} 
};

void printTree(TreeNode* root, int depth);
void treeBuilder(TreeNode* right, TreeNode* left, Node8 front, Node* back);
void treePush(TreeNode *&top, char treevalue);
bool treePop(TreeNode *&top, char &treevalue);
char treePeek(TreeNode* &top, char treevalue);
