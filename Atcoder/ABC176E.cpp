#include<bits/stdc++.h>
 
using namespace std;

 
int main() {
    int H,W,M;
    cin >> H >> W >> M;

    set<pair<int, int>> bomber;
    // 行ごと、列ごとの和
    vector<int> row_sum(H+1), column_sum(W+1);
    int h,w;

    for (int i = 0; i < M; i++) {
        cin >> h >> w;
        bomber.insert(make_pair(h, w));
        row_sum[h]++;
        column_sum[w]++;
    }


    vector<int> max_row, max_column;
    int max_row_sum = 0, max_column_sum = 0;

    // 行ごとに最大値判定
    for (int i = 1; i <= H; i++) {
        if (row_sum[i] > max_row_sum) {
            max_row = {};
            max_row.push_back(i);
            max_row_sum = row_sum[i];
        } else if (row_sum[i] == max_row_sum) {
            max_row.push_back(i);
        }
    }

    // 列ごとに最大値判定
    for (int j = 1; j <= W; j++) {
        if (column_sum[j] > max_column_sum) {
            max_column = {};
            max_column.push_back(j);
            max_column_sum = column_sum[j];
        } else if (column_sum[j] == max_column_sum) {
            max_column.push_back(j);
        }
    }

    int answer = max_row_sum + max_column_sum - 1;

    for (auto i : max_row) {
        for (auto j : max_column) {
            // 爆弾が含まれていないマスがあったら最大値更新
            if (bomber.find(make_pair(i,j)) == bomber.end()) {
                answer += 1;
                goto RESULT;
            }
        }
    }

    RESULT:
    cout << answer << endl;
	return 0;
}