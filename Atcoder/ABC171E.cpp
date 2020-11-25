#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    long long a_xor;

    a_xor = a[0];

    for (int i = 1; i < N; i++) {
        a_xor ^= a[i];
    }

    long long answer = a_xor ^ a[0];
    cout << answer;

    for (int i = 1; i < N; i++) {
        answer = a_xor ^ a[i];
        cout << " " << answer;
    }

	return 0;
}