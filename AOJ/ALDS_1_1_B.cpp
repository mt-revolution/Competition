#include<bits/stdc++.h>

using namespace std;

// GCD(最大公約数)をユークリッドの互除法で求める
long long gcd(long long x, long long y) {
    if(x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}


int main() {
    long long x,y;
    cin >> x >> y;
    
    cout << gcd(x, y) << endl;
    return 0;
}