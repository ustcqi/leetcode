#include <iostream>
#include <vector>

using namespace std;

void FullPermutation(vector<int> a, int n, int dep, vector<int> result, vector<bool> used) {
    if (dep == n) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            result[dep] = a[i];
            used[i] = true;
            FullPermutation(a, n, dep+1, result, used);
            used[i] = false;
        }
    }
}

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[i] = m;
    }
    
    vector<bool> used(n, false);
    vector<int> result(n);
    FullPermutation(a, 3, 0, result, used);
    
    return 0;
}