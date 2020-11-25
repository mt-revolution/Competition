#include<bits/stdc++.h>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<int>> a(R, vector<int>(C));
    vector<vector<int>> tmp(R, vector<int>(C));
    int tmp_count = 0;
    int back_count = 0;
    int max_count = 0;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    // 行ごとに裏返すか裏返さないか全探索
    for(int biti = 0; biti < (1<<R); biti++) {
        tmp = a;
        for(int i = 0; i < R; i++) {
            if(biti & (1<<i)) {
                for(int j = 0; j < C; j++) {
                    tmp[i][j] = 1 - tmp[i][j];
                }
            }
        }

        // 行の全探索のそれぞれについて列ごとに裏返すか判定
        for(int i = 0; i < C; i++) {
            back_count = 0;
            for(int j = 0; j < R; j++) {
                if(tmp[j][i] == 1) {
                    back_count++;
                }
            }

            if(back_count > R/2) {
                for(int j = 0; j < R; j++) {
                    tmp[j][i] = 1 - tmp[j][i];
                }
            }
        }

        // 結果のカウント
        tmp_count = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(tmp[i][j] == 0) {
                    tmp_count++;
                }
            }
        }

        max_count = max(max_count, tmp_count);
    }

    cout << max_count << endl;
	return 0;
}