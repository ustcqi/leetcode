#include <iostream>
#include <vector> 

using namespace std;

// -1 2 1 3 4
// dp[i][j] = {a[j]>a[j-1] dp[i][j-1] + 1, dp[i][j]}
int MaxOrderSeq(int a[], int n) {
    int max_len = 0;
    vector<int> dp(n, 1);
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < j; i++) {
            if (a[j] > a[i]) {
                dp[j] = max(dp[i] + 1, dp[j-1]);
            }
        }
    }
    return dp[n-1];
}

int main(int argc, char *argv[]) {
    int a[] = {0, -1, 2, 3};
    int ret = MaxOrderSeq(a, 4);
    cout << ret;
    return 0;
}