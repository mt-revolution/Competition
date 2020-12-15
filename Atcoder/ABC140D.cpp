#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,K;
    cin >> N >> K;
    
    string S;
    cin >> S;

    int count = 0;
    
    // 最初の幸福な人の数のカウント
    for (int i = 0; i < N; i++) {
        if (S[i] == 'L') {
            if (i - 1 < 0) {
                continue;
            }

            if (S[i-1] == 'L') {
                count++;
            }
        } else {
            if (i + 1 >= N) {
                continue;
            }

            if (S[i+1] == 'R') {
                count++;
            }
        }
    }

    // 1回の操作で最大2人幸福の人数は増えるが、理論上の最大値はN-1なので小さい方を取る
    int answer = min(count + 2*K, N-1);

    cout << answer << endl;
	return 0;
}