#include<bits/stdc++.h>

using namespace std;

int main() {
	string S,T;
    cin >> S;
    cin >> T;

    int answer = 1000000000;
    int S_ = S.size();
    int T_ = T.size();

    vector<int> count(S_, 0);

    for (int i = 0; i <= S_ - T_; i++) {
        for (int j = 0; j < T_; j++) {
            if (S[i+j] != T[j]) {
                count[i]++;
            }
        }

        answer = min(answer, count[i]);
    }

    cout << answer << endl;
	return 0;
}