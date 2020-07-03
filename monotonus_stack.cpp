#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 单调栈
// 4 3 7 1
// 4 > 3, 7 > 1, 4,3 < 7, result = 2

// a[] = {1, 7, 3, 4}
int func(int a[], int n) {
    stack<int> s;
    s.push(INT_MAX);
    int num = 0;
    for (int i = 0; i < n; i++) {
        // a[i] >= 栈顶元素 则 出栈
        while (!s.empty() && a[i] >= s.top()) {
            num += 1;
            s.pop();
        }
        if (a[i] < s.top() || s.empty()) {
            s.push(a[i]);
        }
    }
    return num;
}

int main(int argc, char *argv[]) {
    int a[] = {1, 7, 3, 4};
    int ret = func(a, 4);
    cout << ret;
    return 0;
}