#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// 输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
// 输出: [-1,3,-1]
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  stack<int> s;
  unordered_map<int, int> dict;
  for (size_t i = 0; i < nums2.size(); i++) {
    while (!s.empty() && nums2[i] > s.top()) {
      int num = s.top();
      s.pop();
      dict.insert({num, nums2[i]});
    }
    s.push(nums2[i]);
  }
  vector<int> result;
  for (size_t i = 0; i < nums1.size(); i++) {
    unordered_map<int, int>::const_iterator iter = dict.find(nums1[i]);
    if (iter != dict.end()) {
      result.push_back(iter->second);
    } else {
      result.push_back(-1);
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  vector<int> result = nextGreaterElement(nums1, nums2);
  for (size_t i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
