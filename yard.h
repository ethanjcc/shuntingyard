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
int dequeue(Node *&front, Node *&back, char &value);

bool isOperator(char c);
int precedence(char op);
bool rtAssociative(char op);

//help from copilot to get treenode struct
struct TreeNode {
  char treedata;
  TreeNode *treenext;
  TreeNode* left;
  TreeNode* right;
  TreeNode(char treevalue);
};

void printTree(TreeNode* root, int depth);
TreeNode* treeBuilder(TreeNode* right, TreeNode* left, Node* front, Node* back);
void treePush(TreeNode *&top, char treevalue);
TreeNode* treePop(TreeNode *&top, char &treevalue);
char treePeek(TreeNode* &top, char treevalue);
void treePush2(TreeNode *&top, TreeNode* &Node);

void prefix(TreeNode* root);
void infix(TreeNode* root);
void postfix(TreeNode* root);
