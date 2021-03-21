#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
class DSU{
 private:
  vector<long long> parent;
  vector<long long> size;
 public:
  long long numComponents;
  explicit DSU(long long& n){
    for (long long i = 0; i < n; ++i){
      parent.push_back(i);
      size.push_back(1);
    }
    numComponents = n;
  }
  long long FindSet(long long& n){
    if (n == parent[n]){
      return n;
    }
    parent[n] = FindSet(parent[n]);
    return parent[n];
  }

  void Union(long long& first, long long& second){
    --first;
    --second;
    first = FindSet(first);
    second = FindSet(second);
    if (first != second){
      if (size[first] < size[second]){
        swap(first, second);
      }
      parent[second] = first;
      size[first] += size[second];
      --numComponents;
    }
  }
};
int main() {
  ifstream in("input.txt");
  long long amountOfCities, amountOfQuerries;
  in >> amountOfCities >> amountOfQuerries;
  DSU dsu(amountOfCities);
  ofstream out("output.txt");
  for (long long i = 0; i < amountOfQuerries; ++i){
    long long first, second;
    in >> first >> second;
    dsu.Union(first,second);
    out << dsu.numComponents << endl;
  }
  in.close();
  out.close();
  return 0;
}
