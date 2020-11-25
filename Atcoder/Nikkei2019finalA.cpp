#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    vector<long long> S(N+1);

    long long max_resource = 0;

    S[0] = 0;

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 累積和
    for(int i = 1; i <= N; i++) {
        S[i] = S[i-1] + A[i-1];
    }

    for(int k = 1; k <= N; k++) {
        max_resource = 0;
        for(int i = 0; i <= N-k; i++) {
            max_resource = max(max_resource, S[i+k] - S[i]);
        }
        cout << max_resource << endl;
    }

	return 0;
}