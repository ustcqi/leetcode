#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
  stack<int> s;
  int size = (int)nums.size();
  vector<int> result(size, -1);
  for (size_t i = 0; i < 2 * size; i++) {
    while (!s.empty() && nums[i%size] > nums[s.top()]) {
      int idx = s.top();
      s.pop();
      result[idx] = nums[i%size];
    }
    s.push(i%size);
  }
  return result;
}

int main(int arc, char* argv[]) {
  vector<int> nums = {1, 2, 3, 5, 2, 0};
  vector<int> result = nextGreaterElements(nums);
  for (size_t i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
