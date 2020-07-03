#include <iostream>

using namespace std;

int MaxSeqSum(int a[], int n) {
    int cur_sum;
    int max_sum;
    cur_sum = max_sum = a[0];
    for (int i = 1; i < n; i++) {
        cur_sum = max(cur_sum + a[i], a[i]);
        max_sum = max(max_sum, cur_sum);
    }
    return max_sum;
}

int main(int argc, char * argv[]) {
    int a[] = {-1, 2, 3, 4, -6, 9, 10};
    int ret = MaxSeqSum(a, 7);
    cout << ret << endl;
}