#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:38000000")
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Node{
 public:
  int key;
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
 public:
  Node(){
    this->key = 0;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
  }
  Node(int key): key(key){
    this->parent = nullptr;
    this->right = nullptr;
    this->left = nullptr;
  };
  Node(int key, Node *parent){
    this->key = key;
    this->parent = parent;
    this->right = nullptr;
    this->left = nullptr;
  }
};

const long long min64 = INT64_MIN;
const long long max64 = INT64_MAX;

bool isBST(Node* node, long long min, long long max) {
  if (node == nullptr){
    return true;
  }
  if (node->key < min || node->key >= max){
    return false;
  }
  return (isBST(node->left, min, node->key) && isBST(node->right, node->key, max));
}
bool isBinarySearch(Node* node) {
  return isBST(node, min64, max64);
}


int main() {
  FILE* in;
  in = fopen("bst.in", "r+");
  int amountOfVertex;
  fscanf(in,"%d", &amountOfVertex);
  Node *nodes = new Node[amountOfVertex];
  int root;
  fscanf(in, "%d", &root);
  nodes[0] = *(new Node(root));
  for (int i = 1; i < amountOfVertex; i++){
    int node, parent;
    fscanf(in,"%d", &node);
    fscanf(in, " %d", &parent);
    nodes[i] = *(new Node(node, &nodes[parent - 1]));
    char destination;
    fscanf(in, " %c", &destination);
    if (destination == 'L'){
      nodes[parent - 1].left = &nodes[i];
    }else if (destination == 'R'){
      nodes[parent - 1].right = &nodes[i];
    }
  }
  fclose(in);
  FILE* out;
  out = fopen("bst.out", "w+");
  isBinarySearch(&nodes[0]) ? fprintf(out, "%s", "YES") : fprintf(out, "%s", "NO");
  fclose(out);
  return 0;
}
