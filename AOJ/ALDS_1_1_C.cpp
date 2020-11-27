#include<bits/stdc++.h>

using namespace std;

// 素数判定
bool is_prime(long long N) {
    if(N == 1) {
        return false;
    }

    for (long long a = 2; a * a <= N; a++) {
        if(N % a == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    long long num;
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (is_prime(num) == true) {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}