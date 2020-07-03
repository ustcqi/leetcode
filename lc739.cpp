#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
  stack<int> s;
  int size = (int)T.size();
  vector<int> result(size, 0);
  for (size_t i = 0; i < size; i++) {
    while (!s.empty() && T[i] > T[s.top()]) {
      int idx = s.top();
      s.pop();
      result[idx] = i - idx;
    }
    s.push(i);
  }
  return result;
}

int main(int argc, char *argv[]) {
  vector<int> T = {1, 2, 3, 4, 5, 4, 5, 6};
  vector<int> result = dailyTemperatures(T);
  for (size_t i = 0; i < T.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
