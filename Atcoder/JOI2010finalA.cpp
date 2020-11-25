#include<bits/stdc++.h>

using namespace std;

const long long MOD = 100000;

int main() {
    int n,m;
    cin >> n >> m;

    vector<int> a(m+1);
    vector<int> town(m+1);
    vector<long long> s(n);
    vector<long long> cumu_s(n+1);

    s[0] = 0;

    for(int i = 1; i < n; i++) {
        cin >> s[i];
    }

    a[0] = 1;
    town[0] = 1;

    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        town[i] = town[i-1] + a[i];
    }

    // 累積和
    cumu_s[0] = 0;

    for(int i = 1; i <= n; i++) {
        cumu_s[i] = cumu_s[i-1] + s[i-1];
    }

    long long answer = 0;

    for(int i = 1; i <= m; i++) {
        answer = (answer + abs(cumu_s[town[i]] - cumu_s[town[i-1]])) % MOD;
    }

    cout << answer << endl;
	return 0;
}