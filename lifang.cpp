#include <iostream>
#include <cmath>
using namespace std;

float bisearch(float x, float l, float r) {
    if (r - l < 0.000001) return l + (r - l) /2;
    float mid = l + (r - l) /2;
    if (abs(mid * mid * mid - x) <= 0.00001) { 
        return mid;
    } else if (mid * mid * mid - x > 0.00001) {
        return bisearch(x, l, mid);
    } else if (mid * mid * mid - x < 0.00001) {
        return bisearch(x, mid, r);
    }
    return 0.0;
}
// x > 0  
float lifang(float x) {
    float ret = 0.0;
    if (x == 0) return 0.0;
    if (x >= 1) ret = bisearch(x, 0, x);
    else if (x>0 && x < 1) ret = bisearch(x, 0, 1);
    return ret;
}
int main() {
    float x = -0.8;
    while (true) {
        cin >> x;
        float ret = 0.0;
        if (x < 0) {
            ret = lifang(-x); 
            cout << -ret << endl;
        } else {
            ret = lifang(x); 
            cout << ret << endl;
        }
    }
}