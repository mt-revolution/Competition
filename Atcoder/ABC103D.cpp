#include<bits/stdc++.h>

using namespace std;


int main() {
    int N,M;
    cin >> N >> M;

    int a,b;
    
    // 右端、左端
    vector<pair<int, int>> rule(M);

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        rule[i] = make_pair(b, a);
    }

    // 右端で昇順ソート
    sort(rule.begin(), rule.end());

    // 現在の橋の左端
    int tmp_bridge = -1000000000;
    int answer = 0;

    for (int i = 0; i < M; i++) {
        // 見ている区間の左端が橋の左端より大きいとき、新しく左端が(見ている区間の右端-1)の橋をなくす
        if (rule[i].second > tmp_bridge) {
            tmp_bridge = rule[i].first - 1;
            answer++;
        }
    }

    cout << answer << endl;
	return 0;
}