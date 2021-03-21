#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
void LCS(std::vector<int>& firstArr, std::vector<int>& secondArr){
  std::ofstream out("output.txt");
  std::unordered_map<int, int> mapsIndexes;
  for (int i = 0; i < firstArr.size(); i++) {
    mapsIndexes[firstArr[i]] = i + 1;
  }
  std::vector<int> tmp;
  for (int i = 0; i < secondArr.size(); i++) {
    if (mapsIndexes.find(secondArr[i]) != mapsIndexes.end()) {
      tmp.push_back(mapsIndexes[secondArr[i]]);
    }
  }
  if (tmp.size()) {
    std::vector<int> lis;
    lis.push_back(tmp[0]);
    for (int i = 1; i < tmp.size(); i++) {
      if (tmp[i] > lis.back()) { lis.push_back(tmp[i]); }
      else if (tmp[i] < lis[0]) { lis[0] = tmp[i]; }
      else {
        auto it = lower_bound(lis.begin(), lis.end(), tmp[i]);
        *it = tmp[i];
      }
    }
    out << lis.size();
    out.close();
  }else{
    out << 0;
    out.close();
  }
}
int main() {
  std::ifstream in("input.txt");
  int firstSize, secondSize;
  in >> firstSize >> secondSize;
  std::vector<int>first;
  std::vector<int>second;
  for (int i = 0; i < firstSize; ++i){
    int element;
    in >> element;
    first.push_back(element);
  }
  for (int i = 0; i < secondSize; ++i){
    int element;
    in >> element;
    second.push_back(element);
  }
  in.close();
  LCS(first, second);
  return 0;
}
