#include <iostream>
#include <vector>

using namespace std;

// -1 2 3 0 4 5
// k=3, result=2
// partition 1: -1 2 3 0 4 5, return 0; 0 < 3-1, Partition(a, 1, 5)
// partition 2: 2 3 0 4 5, => 0 2 3 4 5, return 2; 2 == 3 -1, return result
int Partition(int a[], int l, int r) {
    int key = a[l];
    while (l < r) {
        while (a[r] >= key && l < r) r--;
        a[l] = a[r];
        while (a[l] <= key && l < r) l++;
        a[r] = a[l];
    }
    a[l] = key;
    return l;
}

int SelectKthNumber(int a[], int l, int r, int k) {
    while (l <= r) {
        int p = Partition(a, l, r);
        cout << p << endl;
        for (int i = l; i <= r; i++) cout << a[i] << " ";
        cout << endl;
        if (p == k-1) return a[p];
        else if (p > k-1) r = p - 1;
        else l = p + 1;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    // int a[] = {0, 1, 2, -3, -2, 5};
    int a[] = {-1, 2, 3, 0, 4, 5};
    int ret = SelectKthNumber(a, 0, 5, 1);
    cout << ret;
    return 0;
}