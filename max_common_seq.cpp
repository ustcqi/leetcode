#include <iostream>
#include <vector>
using namespace std;

// abcd acd => 3
// dp[i][j] = {s1[i] == s[j], dp[i-1][j-1] + 1; max(dp[i][j-1], dp[i-1][j])}
int MaxCommonSeq(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 == 0 || len2 == 0) return 0;
    // int dp[len1][len2] = {0};
    vector<vector<int> > dp(len1+1, vector<int>(len2+1, 0));
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            dp[i][j] = s1[i-1] == s2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[len1][len2];
}

int main(int argc, char * argv[]) {
    string s1 = "abcd";
    string s2 = "acd";
    int ret = MaxCommonSeq(s1, s2);
    cout << ret;
    return 0;
}