#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
    cin >> N >> M;

    string S;
    vector<int> s(M), c(M);

    for (int i = 0; i < M; i++) {
        cin >> s[i] >> c[i];
    }

    bool flag;
    string answer = "-1";

    // N=1のとき9から0
    if (N == 1) {
        for (int i = 9; i >= 0; i--) {
            S = to_string(i);

            flag = true;

            for (int i = 0; i < M; i++) {
                if (S[s[i]-1] != (char)('0'+c[i])) {
                    flag = false;
                    break;
                }
            }

            if (flag == true) {
                answer = S;
            }
        }
    // N=2,3のとき10^N-1から10^(N-1)まで
    } else {
        for (int i = pow(10, N) - 1; i >= pow(10, N-1); i--) {
            S = to_string(i);

            flag = true;

            for (int i = 0; i < M; i++) {
                if (S[s[i]-1] != (char)('0'+c[i])) {
                    flag = false;
                    break;
                }
            }

            if (flag == true) {
                answer = S;
            }
        }
    }

    cout << answer << endl; 
	return 0;
}