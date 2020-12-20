#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    
    // 終端、始端
    vector<pair<int, int>> robot(N);
    int X,L;

    for (int i = 0; i < N; i++) {
        cin >> X >> L;
        robot[i] = make_pair(X + L, X - L);
    }

    // 終端で昇順ソート
    sort(robot.begin(), robot.end());
    
    // 現在の終端
    int tmp_right = robot[0].first;
    int answer = N;

    for (int i = 1; i < N; i++) {
        // 見ているところの始端が終端未満の場合取り除く
        if (robot[i].second < tmp_right) {
            answer--;
        // 終端を更新
        } else {
            tmp_right = robot[i].first;
        }
    }

    cout << answer << endl;
	return 0;
}