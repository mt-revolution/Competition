#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int x,y;
    vector<vector<bool>> friends(N, vector<bool>(N, false));
    vector<int> tmp;
    int tmp_size;
    int max_group = 0;
    bool flag;

    for(int i = 0; i < M; i++) {
        cin >> x >> y;
        x--, y--;
        friends[x][y] = true;
    }

    // 派閥を作っている人の組み合わせでbit全探索
    for(int biti = 1; biti < (1<<N); biti++) {
        flag = true;
        tmp = {};
        
        for(int i = 0; i < N; i++) {
            if(biti & (1<<i)) {
                tmp.push_back(i);
            }
        }

        tmp_size = tmp.size();

        // 派閥の中が全員ちゃんと知り合いかどうか調べる
        for(int i = 0; i < tmp_size-1; i++) {
            for(int j = i+1; j < tmp_size; j++) {
                if(friends[tmp[i]][tmp[j]] == false) {
                    flag = false;
                    break;
                }
            }

            if (flag == false) {
                break;
            }
        }

        if(flag == true) {
            max_group = max(max_group, tmp_size);
        }
    }

    cout << max_group << endl;
	return 0;
}