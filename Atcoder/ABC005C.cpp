#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
    cin >> T;
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // たこ焼きの在庫があるかどうか
    vector<int> id(N, 1);

    int M;
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    // それぞれの客について
    for (int i = 0; i < M; i++) {
        bool flag = false;
        // それぞれのたこ焼きについて到着時間からT秒以前に作られたたこやきを早い順に食べる
        for (int j = 0; j < N; j++) {
            if (A[j] >= B[i] - T && A[j] <= B[i]) {
                if (id[j] == 1) {
                    id[j] = 0;
                    flag = true;
                    break;
                }
            }
        }

        // たこ焼きがないとき
        if (flag == false) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;    
	return 0;
}