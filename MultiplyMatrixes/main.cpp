#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int func(vector<int>& v) {
  int size = v.size() - 1;
  int dp[size][size];
  for (int i = 0; i < size; ++i) {
    dp[i][i] = 0;
  }
  for (int l = 1; l < size; ++l) {
    for (int i = 0; i < size - l; ++i) {
      int j = i + l;
      dp[i][j] = INT32_MAX;
      for (int k = i; k < j; ++k) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + v[i] * v[k + 1] * v[j + 1]);
      }
    }
  }
  return dp[0][size - 1];
}


int main() {
  ifstream in("input.txt");
  int numOfMatrixes;
  in >> numOfMatrixes;
  vector<int> vec;
  int firstElement;
  in >> firstElement;
  vec.push_back(firstElement);
  for (int i = 0; i < numOfMatrixes - 1; ++i){
    int first, second;
    in >> first >> second;
    vec.push_back(first);
  }
  int lastElement;
  in >> lastElement;
  in.close();
  vec.push_back(lastElement);
  ofstream out("output.txt");
  int ans = func(vec);
  out << ans;
  out.close();
  return 0;
}
