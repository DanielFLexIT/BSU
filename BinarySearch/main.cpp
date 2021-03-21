#include <iostream>

int lowerBound(int mas[], int start, int end, int element){
  while(start < end){
    int mid = start + (end - start)/2;
    if(element <= mas[mid]) {
      end = mid;
    }
    else {
      start = mid + 1;
    }
  }
  return start;
}

using namespace std;

int main() {
  int length, amountOfQueries;
  cin >> length;
  int mas[length];

  for (int i = 0; i < length; ++i){
    cin >> mas[i];
  }
  cin >> amountOfQueries;
  while (amountOfQueries){
    int element;
    cin >> element;
    int l1 = lowerBound(mas, 0, length, element);
    int l2 = lowerBound(mas, 0, length, element + 1);
    if (l1 - l2) {
      cout << 1 << " " <<  l1 << " " << l2 << endl;
    } else{
      cout << 0 << " " << l1 << " " << l2 << endl;
    }
    --amountOfQueries;
  }
  return 0;
}