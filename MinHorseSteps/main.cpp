#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:167772160")
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int main() {
  int n,m;
  FILE* in = fopen("input.txt", "r");
  FILE* out = fopen("output.txt", "w");

  fscanf(in, "%d", &n);
  fscanf(in, "%d", &m);

  vector<vector<int>> desk (n, vector<int>(m, 0));
  vector<vector<int>> dp(n, vector<int>(m ,0));

  int num;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      fscanf(in, "%d", &num);
      desk[i][j] = num;
      dp[i][j] = num;
    }
  }

  int x1, x2, y1, y2;

  fscanf(in, "%d", &x1);
  fscanf(in, "%d", &y1);
  fscanf(in, "%d", &x2);
  fscanf(in, "%d", &y2);

  queue<pair<int, int>> q;
  q.push(pair<int, int>(x1, x2));

  while(!q.empty()){
    pair<int, int> p = q.front();
    q.pop();

    if(dp[p.first][p.second] != 0){
      continue;
    }

    if(p.first - )

  }



  return 0;
}
