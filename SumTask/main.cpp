#include <iostream>
#include <vector>
#include <string>
using namespace std;
void doBuild(vector<long long> &array, vector<long long>& tree, const long long &v, const long long& l, const long long& r){
  if (r - l == 1){
    tree[v] = array[l];
  }
  else{
    long long m = (l + r) / 2;
    doBuild(array, tree, 2 * v, l, m);
    doBuild(array, tree, 2 * v + 1, m, r);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  }
}
void build(vector<long long> &array, vector<long long> &tree, const long long& r) {
  doBuild(array, tree, 1, 0, r);
}
void doAdd(vector<long long>&tree, const long long& v, const long long& l, const long long& r, const long long& i, const long long& x) {
  if (r - l == 1) {
    tree[v] += x;
    return;
  }
  long long m = (l + r) / 2;
  if (i < m){
    doAdd(tree, 2 * v, l, m, i, x);
  }
  else{
    doAdd(tree, 2 * v + 1, m, r, i, x);
  }
  tree[v] = tree[2 * v] + tree[2 * v + 1];
}
void add(vector<long long>&tree, const long long& n, const long long& i, const long long& x) {
  doAdd(tree, 1, 0, n, i, x);
}
long long doFindSum(vector<long long>&tree, const long long& v, const long long & tl, const long long& tr, const long long& il, const long long& ir){
  if (ir == tr && il == tl){
    return tree[v];
  }
  long long m = (tl + tr) / 2;
  if (ir <= m){
    return doFindSum(tree, 2 * v, tl, m, il, ir);
  }
  if (m <= il){
    return doFindSum(tree, 2 * v + 1, m, tr, il, ir);
  }
  return (doFindSum(tree, 2 * v, tl, m, il, m) + doFindSum(tree, 2 * v + 1, m, tr, m, ir));
}
void processQuerries(vector<long long>&tree, const long long& size){
  string str;
  cin >> str;
  int a, b;
  cin >> a >> b;
  if (str == "FindSum") {
    cout << doFindSum(tree, 1, 0, size, a, b) << endl;
  }
  if (str == "Add") {
    add(tree, size, a, b);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long amountOfElements;
  cin >> amountOfElements;
  vector<long long> array;
  for (long long i = 0; i < amountOfElements; ++i){
    int element;
    cin >> element;
    array.push_back(element);
  }
  long long number_of_queries = 0;
  cin >> number_of_queries;
  vector<long long> tree(4 * amountOfElements);
  build(array, tree, amountOfElements);
  for (int i = 0; i < number_of_queries; i++) {
    processQuerries(tree, amountOfElements);
  }
  return 0;
}