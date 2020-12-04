#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    // 終端、始端の順で格納
    vector<pair<int, int>> activities(n);

    for (int i = 0; i < n; i++) {
        cin >> activities[i].second >> activities[i].first;
    }

    // 区間の終端でソート
    sort(activities.begin(), activities.end());

    // 現在の終端
    int current_end = 0;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        // 現在の終端より見ている始端が大きければ現在の終端を見ている終端で更新
        if (activities[i].second > current_end) {
            answer++;
            current_end = activities[i].first;
        }
    }

    cout << answer << endl;
	return 0;
}