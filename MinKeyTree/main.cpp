#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:38000000")
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Node{
public:
Node* left;
Node* right;
Node* parent;
long long h;
long long key;
long long msl;
long long list;
long long b;
long long a;
public:
Node(){
left = nullptr;
right = nullptr;
parent = nullptr;
key = 0;
}
Node(long long element){
left = nullptr;
right = nullptr;
parent = nullptr;
key = element;
}
};
class Tree{
public:
Node* root;
long long maxMSL;
long long minKey;
bool flag;
Tree(){
root = nullptr;
maxMSL = 0;
minKey = INT64_MAX;
flag = false;
}
void doAddElement(long long& element){
addElement(element, root);
}
void addElement(long long& element, Node* node){
if (root == nullptr){
root = new Node(element);
root->a = 0;
return;
}
if (element > node->key){
if (node->right == nullptr){
node->right = new Node(element);
node->right->parent = node;
return;
}
return addElement(element, node->right);
}
if(element < node->key){
if (node->left == nullptr){
node->left = new Node(element);
node->left->parent = node;
return;
}
return addElement(element, node->left);
}
}
Node* deleteElement(Node* node, long long& element){
if (node == nullptr){
return nullptr;
}
if (element < node->key){
node->left = deleteElement(node->left, element);
return node;
}
else if(element > node->key){
node->right = deleteElement(node->right, element);
return node;
}
if(node->left == nullptr){
return node->right;
}
else if(node->right == nullptr){
return node->left;
}
else{
long long minkey = findMin(node->right)->key;
node->key = minkey;
node->right = deleteElement(node->right,minkey);
return node;
}
}
Node* findMin(Node* node){
if (node->left != nullptr){
return findMin(node->left);
}else{
return node;
}
}
void TranversePreOrder(FILE* file){
doTranversePreOrder(root, file);
}
void doTranversePreOrder(Node* node, FILE* file){
if (node == nullptr){
return;
}
fprintf(file, "%lld\n", node->key);
doTranversePreOrder(node->left, file);
doTranversePreOrder(node->right, file);
}
void doSetHeight(Node* node){
if (node != nullptr){
doSetHeight(node->left);
doSetHeight(node->right);
if (node->left == nullptr && node->right == nullptr){
node->h = 0;
}
else if(node->right == nullptr){
node->h = node->left->h + 1;
}
else if(node->left == nullptr){
node->h = node->right->h + 1;
}
else{
node->h = max(node->left->h, node->right->h) + 1;
}
}
}
void doSetMSL(Node* node){
if(node != nullptr){
doSetMSL(node->left);
doSetMSL(node->right);
if (node->left == nullptr && node->right == nullptr){
node->msl = 0;
}
else if(node->left == nullptr){
node->msl = node->right->h + 1;
}
else if(node->right == nullptr){
node->msl = node->left->h + 1;
}
else{
node->msl = node->right->h + node->left->h + 2;
}
if (node->msl > this->maxMSL){
this->maxMSL = node->msl;
}
}
}
void doSetLists(Node* node){
if(node != nullptr){
doSetLists(node->left);
doSetLists(node->right);
if(node->left == nullptr && node->right == nullptr) {
node->list = 1;
}
else if(node->right == nullptr){
node->list = node->left->list;
}
else if(node->left == nullptr){
node->list = node->right->list;
}
else{
if (node->left->h == node->right->h){
node->list = node->left->list + node->right->list;
}
else if(node->right->h > node->left->h){
node->list = node->right->list;
}
else{
node->list = node->left->list;
}
}
}
}
void doSetB(Node* node) {
if (node != nullptr) {
doSetB(node->left);
doSetB(node->right);
if (node->msl == this->maxMSL){
if(node->left == nullptr && node->right != nullptr){
node->b = node->right->list;
}
else if(node->right == nullptr && node->left != nullptr){
node->b = node->left->list;
}
else{
node->b = node->left->list * node->right->list;
}
}
else{
node->b = 0;
}
}
}
void doSetA(Node* node){
if (node != nullptr){
if (node->left == nullptr && node->right == nullptr){

}
else if (node->left == nullptr && node->right != nullptr){
node->right->a = node->b + node->a;
}
else if(node->right == nullptr && node->left != nullptr){
node->left->a = node->b + node->a;
}
else if(node->left != nullptr && node->right != nullptr){
if (node->left->h > node->right->h){
node->left->a = node->a + node->b;
node->right->a = node->b;
}
else if(node->right->h > node->left->h){
node->right->a = node->a + node->b;
node->left->a = node->b;
}
else{
node->left->a = node->b + node->left->list * (node->a / node->list);
node->right->a = node->b + node->right->list * (node->a / node->list);
}
}
doSetA(node->left);
doSetA(node->right);
}
}
void doSetMinKey(Node* node){
if (node != nullptr){
doSetMinKey(node->left);
if ((node->a + node->b) % 2 != 1 && (node->a + node->b)){
flag = true;
if (node->key <= this->minKey){
this->minKey = node->key;
}
}
doSetMinKey(node->right);
}
}
void setMarks(){
doSetHeight(root);
doSetMSL(root);
doSetLists(root);
doSetB(root);
doSetA(root);
doSetMinKey(root);
}
};

int main() {
Tree* tree = new Tree();
ifstream in("tst.in");
while (!(in.eof())){
long long element;
in >> element;
tree->doAddElement(element);
}
in.close();
FILE* out;
tree->setMarks();
out = fopen("tst.out", "w+");
cout << tree->minKey;
if(tree->flag){
tree->root = tree->deleteElement(tree->root, tree->minKey);
}
tree->TranversePreOrder(out);
fclose(out);
return 0;
}