#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
void powersOfTwo(long long& number, FILE* file){
  long long bin = 0;
  long long power = 1;
  long long counter = 0;
  long long digit;
  while (number)
  {
    digit = number % 2;
    if (digit){
      fprintf(file, "%lld\n", counter);
    }
    ++counter;
    bin += digit * power;
    power *= 10;
    number /= 2;
  }
}
int main() {
  ifstream in("input.txt");
  long long num;
  in >> num;
  FILE* out;
  out = fopen("output.txt", "w+");
  powersOfTwo(num, out);
  fclose(out);
  return 0;
}
