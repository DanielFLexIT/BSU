#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:167772160")
#include <iostream>
#include <fstream>
const long long mod = (1e9) + 7;
using namespace std;
long long modPower(long long &n, long long& k)
{
  if (n - k) {
    long long remainder = 1;
    while (k) {
      if (k % 2) {
        remainder = (remainder * n) % mod;
      }
      n = (n * n) % mod;
      k >>= 1;
    }
    return remainder;
  }
  return 0;
}
long long calculateCombination(const int& n, const int& k){
  long long num = 1;
  long long denom = 1;
  for (int i = n; i > n - k; --i){
    num = (num * i) % mod;
  }
  for (int i = 1; i <= k; ++i){
    denom = (denom * i) % mod;
  }
  long long a = mod - 2;
  long long remainder = modPower(denom, a);
  return (num * remainder) % mod;
}

int main() {
  ifstream in("input.txt");
  int rows, columns;
  in >> rows >> columns;
  in.close();
  ofstream out("output.txt");
  out << calculateCombination(columns + rows - 2, rows - 1);
  out.close();
  return 0;
}
