#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
    cin >> n;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // 色の区間ごとの支持する消費者の数
    vector<int> customer(1000002, 0);

    // いもす法
    for(int i = 0; i < n; i++) {
        customer[a[i]] += 1;
        customer[b[i]+1] -= 1;
    }

    for(int i = 1; i < 1000001; i++) {
        customer[i] += customer[i-1];
    }

    int answer = 0;

    for(int i = 0; i < 1000001; i++) {
        answer = max(answer, customer[i]);
    }

    cout << answer << endl;
	return 0;
}