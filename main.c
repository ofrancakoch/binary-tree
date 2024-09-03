#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  struct Node *RightNode;
  struct Node *LeftNode;
  int value;
} Tree;

Tree *createNode(int val);
Tree *insertNode(Tree *node, int val);
void showTree(Tree *node, int tabCount);
void preOrder(Tree *node);
void inOrder(Tree *node);
void postOrder(Tree *node);
void tabFormat(int val);

int main(void) {
  Tree *Node = createNode(25);
  //example input
  insertNode(Node, 22);
  insertNode(Node, 23);
  insertNode(Node, 24);
  insertNode(Node, 21);
  insertNode(Node, 20);
  insertNode(Node, 29);
  insertNode(Node, 28);
  insertNode(Node, 30);
  insertNode(Node, 27);
  insertNode(Node, 35);
  insertNode(Node, 33);
  insertNode(Node, 38);
  insertNode(Node, 55);
  insertNode(Node, 37);
  showTree(Node, 0);
  puts("\nPre Order:\n");
  preOrder(Node);
  puts("\n\nIn Order:\n");
  inOrder(Node);
  puts("\n\nPost Order:\n");
  postOrder(Node);
  return 0;
}

//creates a new node
Tree *createNode(int val) {
  Tree *newNode = (Tree *)malloc(sizeof(Tree));
  newNode->RightNode = NULL;
  newNode->LeftNode = NULL;
  newNode->value = val;
  return newNode;
}


void tabFormat(int val){
  for(int i = 0; i < val*2; i++){
    printf("-");
  }
}

Tree *insertNode(Tree *node, int val) {
  if (node == NULL){
    node = createNode(val);
    return node;
  }
  if (val < node->value) {
    node->LeftNode = insertNode(node->LeftNode, val);
  }else if (val > node->value) {
    node->RightNode = insertNode(node->RightNode, val);
  }
  return node;
}


void showTree(Tree *node, int tabCount) {
  if (node != NULL) {
    tabFormat(tabCount);
    printf("|%d \n", node->value);
    showTree(node->RightNode, tabCount + 1);
    showTree(node->LeftNode, tabCount + 1);
  }
}


void preOrder(Tree *node) {
  if (node != NULL) {
    printf("|%d ", node->value);
    preOrder(node->LeftNode);
    preOrder(node->RightNode);
  }
}

void inOrder(Tree *node) {
  if (node != NULL) {
    inOrder(node->LeftNode);
    printf("|%d ", node->value);
    inOrder(node->RightNode);
  }
}

void postOrder(Tree *node) {
  if (node != NULL) {
    postOrder(node->LeftNode);
    postOrder(node->RightNode);
    printf("|%d ", node->value);
  }
}




