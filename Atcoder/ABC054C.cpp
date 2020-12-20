#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,M;
    cin >> N >> M;
    
    // 隣接行列
    vector<vector<int>> G(N, vector<int>(N, 0));
    int a,b;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        G[a][b] = 1;
        G[b][a] = 1;
    }

    // ノード0以外の順列
    vector<int> perm;
    for (int i = 1; i < N; i++) {
        perm.push_back(i);
    }

    int answer = 0;

    // ノード0以外の順列全探索
    do {
        bool flag = true;

        if (G[0][perm[0]] == 0) {
            flag = false;
        }

        for (int i = 0; i < perm.size()-1; i++) {
            if (G[perm[i]][perm[i+1]] == 0) {
                flag = false;
                break;
            }
        }

        if (flag == true) {
            answer++;
        }
    } while(next_permutation(perm.begin(), perm.end()));

    cout << answer << endl;
	return 0;
}