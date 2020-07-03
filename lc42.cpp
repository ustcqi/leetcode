#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

// idea: 单调栈, 先手写几种情况,然后找出规律,规律是大的元素放到栈底，下一个元素小于栈的 top 元素才入栈，否则出栈
// 计算时先获取栈顶元素的下标和值，还需要栈顶元素出栈后新的栈顶元素大小，取当前元素和这个新栈顶元素最小值，再和出栈元素相减得到高度差，再乘以长度
int trap(vector<int> &hight) {
  int result = 0;
  stack<int> s;
  s.push(0);
  for (size_t i = 0; i < hight.size(); i++) {
    while (!s.empty() && hight[i] > hight[s.top()]) {
      int prev_index = s.top();
      int prev_hight = hight[prev_index];
      s.pop();
      if (!s.empty()) {
        result += (min(hight[i], hight[s.top()]) - prev_hight) * (i - s.top() - 1);
      }
    }
    s.push(i);
  }
  return result;
}

int main(int argc, char *argv[]) {
  vector<int> hight = {2, 0, 0, 1, 2};
  int result = trap(hight);
  cout << result << endl;
  return 0;
}
