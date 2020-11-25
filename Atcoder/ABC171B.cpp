#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,K;
    cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    sort(P.begin(), P.end());

    int answer = 0;

    for (int i = 0; i < K; i++) {
        answer += P[i];
    }

    cout << answer << endl;
	return 0;
}