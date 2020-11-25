#include<bits/stdc++.h>

using namespace std;

int m, n;
int max_ice = 0;

// 正当な移動か調べる
bool valid_move(vector<vector<int>> &field, vector<vector<bool>> &passed, int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }

    if(field[i][j] == 0 || passed[i][j] == true) {
        return false;
    }

    return true;
}

// 今いる薄氷から渡れる薄氷の数の最大値を調べて更新
void count_max_ice(vector<vector<int>> &field, vector<vector<bool>> &passed, int i, int j, vector<vector<int>> &count) {
    passed[i][j] = true;

    if(valid_move(field, passed, i+1, j) == true) {
        count[i+1][j] = count[i][j] + 1;
        count_max_ice(field, passed, i+1, j, count);
    }

    if(valid_move(field, passed, i-1, j) == true) {
        count[i-1][j] = count[i][j] + 1;
        count_max_ice(field, passed, i-1, j, count);
    }

    if(valid_move(field, passed, i, j+1) == true) {
        count[i][j+1] = count[i][j] + 1;
        count_max_ice(field, passed, i, j+1, count);
    }

    if(valid_move(field, passed, i, j-1) == true) {
        count[i][j-1] = count[i][j] + 1;
        count_max_ice(field, passed, i, j-1, count);
    }

    passed[i][j] = false;
    max_ice = max(max_ice, count[i][j]);
}

int main() {
    cin >> m >> n;

    vector<vector<int>> field(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] == 1) {
                vector<vector<int>> count(n, vector<int>(m, 0));
                vector<vector<bool>> passed(n, vector<bool>(m, false));
                count[i][j] = 1;
                count_max_ice(field, passed, i, j, count);
            }
        }
    }

    cout << max_ice << endl;
	return 0;
}