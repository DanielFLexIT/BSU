#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:38000000")
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
int main() {
  long long ans;
  ifstream in("in.txt");
  long long length;
  in >> length;
  long long amountOfGroups;
  in >> amountOfGroups;
  if (amountOfGroups) {
    for (long i = 0; i < amountOfGroups; ++i) {
      long long element;
      in >> element;
      length -= element;
    }
    in.close();
    ++length;
    if (length <= 0) {
      ans = 0;
    }
    else {
      if (amountOfGroups > length) {
        ans = 0;
      } else {
        long long **pascalTriangle = new long long *[length + 1];
        for (int i = 0; i < length + 1; ++i) {
          pascalTriangle[i] = new long long[length + 1];
        }
        for (long long i = 0; i < length + 1; ++i) {
          pascalTriangle[i][0] = 1;
          pascalTriangle[i][i] = 1;
          for (long long j = 1; j < i; j++) {
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
          }
        }
        ans = pascalTriangle[length][amountOfGroups];
        delete[] pascalTriangle;
      }
    }
  }else {
    ans = 1;
    in.close();
  }
  FILE *out;
  out = fopen("out.txt", "w+");
  fprintf(out, "%lld", ans);
  fclose(out);
  return 0;
}