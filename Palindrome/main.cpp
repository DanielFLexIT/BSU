#include <fstream>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
void longestPalindrome(const string& s){
    int columns = s.length();
    int rows = s.length();
    int **dp = new int*[rows + 1];
    for(int i = 0; i < rows + 1; ++i){
      dp[i] = new int[columns + 1];
    }
    string reversed = s;
    std::reverse(reversed.begin(), reversed.end());
    for (int i = 0; i <= columns; ++i){
      for (int j = 0; j <= rows; ++j){
        if (i == 0 || j == 0){
          dp[i][j] = 0;
        }
        else if (s[i - 1] == reversed[j - 1]){
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else{
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    int index = dp[rows][columns];
    string ans;
    ans.resize(index);
    int tmpRows = rows;
    int tmpCols = columns;
    while (tmpRows && tmpCols){
      if (s[tmpRows - 1] == reversed[tmpCols - 1]){
        ans[index - 1] = s[tmpRows - 1];
        --tmpRows;
        --tmpCols;
        --index;
      }
      else if (dp[tmpRows][tmpCols - 1] < dp[tmpRows - 1][tmpCols]){
        --tmpRows;
      }else{
        --tmpCols;
      }
    }
    int size = ans.size();
    ofstream out("output.txt", ios::out);
    out << size << "\n" << ans;
    out.close();
    delete[] dp;
}


int main() {
  ifstream in("input.txt");
  string s;
  in >> s;
  in.close();
  longestPalindrome(s);
  return 0;
}