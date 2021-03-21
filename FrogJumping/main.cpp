#include <fstream>
using namespace std;

int maxAmountOfMosquitos(int array[], const int& length){
  if (length == 1){
    return array[0];
  }
  if(length == 2){
    return -1;
  }
  int dp[length];
  dp[0] = array[0];
  dp[1] = INT32_MIN;
  dp[2] = array[0] + array[2];
  if (length == 3){
    return dp[2];
  }
  for (int i = 3; i < length; ++i){
    dp[i] = max(dp[i - 3], dp[i - 2]) + array[i];
  }
  return dp[length - 1];
}


int main() {

  ifstream in("input.txt");
  int amountOfLilies;
  in >> amountOfLilies;
  int array[amountOfLilies];
  for (int i = 0; i < amountOfLilies; ++i){
    int amountOfMosquitos;
    in >> amountOfMosquitos;
    array[i] = amountOfMosquitos;
  }
  in.close();
  ofstream out("output.txt");
  out << maxAmountOfMosquitos(array, amountOfLilies);
  out.close();
  return 0;
}
