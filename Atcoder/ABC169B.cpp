#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    long long answer = 1, tmp_answer;

    vector<long long> A(N);

    // 0が含まれていた場合
    for (int i = 0; i < N; i++) {
        cin >> A[i];

        if (A[i] == 0) {
            cout << "0" << endl;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        tmp_answer = answer;

        if ((__int128)tmp_answer * A[i] > (__int128)1e18) {
            answer = -1;
            break;
        }

        answer *= A[i];
    }

    cout << answer << endl;
	return 0;
}