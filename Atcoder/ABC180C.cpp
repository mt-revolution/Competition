#include<bits/stdc++.h>

using namespace std;


int main() {
    long long N;
    cin >> N;

    set<long long> divisor;

    for (long long i = 1; i*i <= N; i++) {
        if (N % i == 0) {
            divisor.insert(i);
            divisor.insert(N/i);
        }
    }

    for (auto i : divisor) {
        cout << i << endl;
    }
    
    return 0;
}