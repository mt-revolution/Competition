#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    
    int A,x_tmp,y_tmp;
    vector<vector<int>> x(N, vector<int>{}), y(N, vector<int>{});
    
    for (int i = 0; i < N; i++) {
        cin >> A;
        
        for (int j = 0; j < A; j++) {
            cin >> x_tmp >> y_tmp;
            x_tmp--;
            x[i].push_back(x_tmp);
            y[i].push_back(y_tmp);
        }
    }

    int count, answer = 0;
    bool flag;

    // 誰が正直者で誰が不親切かbit全探索(1:正直者、0:不親切な者)
    for (int biti = 0; biti < (1<<N); biti++) {
        vector<int> honest(N, 0);
        count = 0;
        flag = true;

        // 正直者の仮定をして印をつける
        for (int i = 0; i < N; i++) {
            if (biti & (1<<i)) {
                count++;
                honest[i] = 1;
            }
        }

        // 各正直者の発言に矛盾がないか調べる
        for (int i = 0; i < N; i++) {
            if (biti & (1<<i)) {
                for (int j = 0; j < x[i].size(); j++) {
                    // 矛盾がある場合
                    if (honest[x[i][j]] != y[i][j]) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag == false) {
                break;
            }
        }

        // 矛盾がなければ最大値更新
        if (flag == true) {
            answer = max(answer, count);   
        }
    }

    cout << answer << endl;
	return 0;
}