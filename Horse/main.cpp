#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
struct pointHorse{
  pointHorse(int x, int y){
    this->x_ = x;
    this->y_ = y;
  }
  pointHorse()= default;
  int x_ = 0;
  int y_ = 0;
};
int main() {
  pointHorse a(1,2);
  pointHorse b(-1, 2);
  pointHorse c(1, -2);
  pointHorse d(-1, -2);
  pointHorse e(2, 1);
  pointHorse f(-2, 1);
  pointHorse g(2, -1);
  pointHorse h(-2, -1);
  pointHorse arr[8];
  arr[0] = a;
  arr[1] = b;
  arr[2] = c;
  arr[3] = d;
  arr[4] = e;
  arr[5] = f;
  arr[6] = g;
  arr[7] = h;
  ifstream in("in.txt");
  int n;
  in >> n;
  int m;
  in >> m;
  int chessboard[n][m];
  int dp[n][m];
  for (int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      int element;
      in >> element;
      chessboard[i][j] = element;
      dp[i][j] = -1;
    }
  }
  int xStart, yStart, xEnd, yEnd;
  in >> xStart >> yStart >> xEnd >> yEnd;
  --xStart;
  --yStart;
  --xEnd;
  --yEnd;
  in.close();
  dp[xStart][yStart] = 0;
  ofstream out("out.txt");
  if (chessboard[xStart][yStart] == -1 || chessboard[xEnd][yEnd] == -1){
    out << "No";
    out.close();
  }else {
    queue<pointHorse> q;
    pointHorse start(xStart, yStart);
    q.push(start);
    while (!q.empty()) {
      pointHorse current = q.front();
      for (auto & i : arr) {
        pointHorse tmp;
        tmp.x_ += current.x_ + i.x_;
        if (tmp.x_ > n - 1 || tmp.x_ < 0) {
          continue;
        }
        tmp.y_ += current.y_ + i.y_;
        if (tmp.y_ > m - 1 || tmp.y_ < 0) {
          continue;
        }
        if (chessboard[tmp.x_][tmp.y_] == -1) {
          continue;
        }
        int previousValue = dp[tmp.x_][tmp.y_];
        int newValue = dp[current.x_][current.y_] + 1;
        if (previousValue < 0 || newValue < previousValue) {
          dp[tmp.x_][tmp.y_] = newValue;
          q.push(tmp);
        }
      }
      q.pop();
    }
    out << dp[xEnd][yEnd];
    out.close();
  }
  return 0;
}
