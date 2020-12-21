#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;
    
    vector<int> w(N);

    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    // スタックの集合の山
    vector<stack<int>> mountain;
    // 最初に先頭を格納
    mountain.push_back({});
    mountain[0].push(w[0]);

    bool flag;

    for (int i = 1; i < N; i++) {
        flag = false;

        // 見ているスタックの一番上がw[i]以上ならば追加
        for (int j = 0; j < mountain.size(); j++) {
            if (w[i] <= mountain[j].top()) {
                mountain[j].push(w[i]);
                flag = true;
                break;
            } 
        }

        // 全てのスタックの一番上がw[i]未満ならば新しくスタックを追加
        if (flag == false) {
            mountain.push_back({});
            mountain.back().push(w[i]);
        }
    }

    cout << mountain.size() << endl;
	return 0;
}