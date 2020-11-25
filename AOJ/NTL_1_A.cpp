#include<bits/stdc++.h>

using namespace std;


int main() {
    long long n;
    cin >> n;

    long long tmp, count;
    vector<pair<long long, long long>> prime;

    tmp = n;

    // 素因数分解
    for(long long i = 2; i*i <= n; i++) {
        if(tmp % i != 0) {
            continue;
        }

        count = 0;

        while(tmp % i == 0) {
            tmp /= i;
            count++;
        }

        if(count > 0) {
            prime.push_back(make_pair(i, count));
        }    
    }

    // 数が残った場合(もともと素数だった場合)
    if(tmp != 1) {
        prime.push_back(make_pair(tmp, 1));
    }

    cout << n << ":";

    for(auto p : prime) {
        for(int i = 0; i < p.second; i++) {
            cout << " " << p.first;
        }
    }
    cout << endl;

	return 0;
}