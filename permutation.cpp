#include <iostream>
#include <vector>

using namespace std;

void Permutation(vector<int> a, int n, int m, int dep) {
    if (dep == n) {
        for (int i = 0; i < n; i++) cout << a[i] << " "; 
        cout << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        a[dep] = i;
        Permutation(a, n, m, dep+1);
        a[dep] = -1;
    }
}

int main(int argc, char *argv[]) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n, -1);
    Permutation(a, n, m, 0);
    return 0;
}