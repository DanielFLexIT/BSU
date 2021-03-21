#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
long long findLength(priority_queue<long long, vector<long long>, greater<>>& queue){
  long long sum = 0;
  while (queue.size() - 1){
    long long first = queue.top();
    queue.pop();
    long long second = queue.top();
    queue.pop();
    sum += first + second;
    queue.push(first + second);
  }
  return sum;
}

int main()
{
  priority_queue<long long,vector<long long>,greater<>> pQueue;
  ifstream in("huffman.in");
  long long amountOfElements;
  in >> amountOfElements;
  for (long long i = 0; i < amountOfElements; ++i){
    long long element;
    in >> element;
    pQueue.push(element);
  }
  in.close();
  long long ans = findLength(pQueue);
  ofstream out("huffman.out");
  out << ans;
  out.close();
  return 0;
}