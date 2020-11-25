#include<bits/stdc++.h>

using namespace std;

// 深さ優先探索(島の発見)
struct dfs {
    vector<vector<int>> map;
    vector<vector<bool>> seen;
    vector<int> di = {1, 1, 1, 0, 0, -1, -1, -1};
    vector<int> dj = {1, 0, -1, 1, -1, 1, 0, -1};
    int x, y;

    dfs(int H, int W) {
        map.assign(H+2, vector<int>(W+2, 0));
        seen.assign(H+2, vector<bool>(W+2, false));
    };

    void set(int i, int j, int in) {
        map[i][j] = in;
    }

    void do_dfs(int i, int j) {
        seen[i][j] = true;

        // (i,j) に隣接している地点を再帰的に探索
        for (int k = 0; k < 8; k++) {
            x = i + di[k], y = j + dj[k];

            if (map[x][y] == 0 || seen[x][y] == true) {
                continue;
            }

            do_dfs(x, y);
        }
    }
};


int main() {
    int w,h,c,count;
    vector<int> answer;

    while (1) {
        cin >> w >> h;

        if (w == 0 && h == 0) {
            break;
        }

        dfs D(h, w);
        count = 0;

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> c;
                D.set(i, j, c);
            }
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (D.map[i][j] == 1 && D.seen[i][j] == false) {
                    D.do_dfs(i, j);
                    count++;
                }
            }
        }

        answer.push_back(count);
    }
    
    for (auto i : answer) {
        cout << i << endl;
    }

    return 0;
}