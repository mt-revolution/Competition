#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,q;
    cin >> n >> q;
    
    queue<pair<string, int>> p;
    string s;
    int t;

    // キューにプロセスを追加
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        p.push(make_pair(s, t));
    }

    int time = 0;
    pair<string, int> tmp;
    
    // キューが空になるまで
    while (p.empty() == false) {
        tmp = p.front();
        p.pop();

        // クオンタム以内にプロセスが終わるとき
        if (tmp.second <= q) {
            time += tmp.second;
            cout << tmp.first << " " << time << endl;
        // クオンタム以内にプロセスが終わらないとき残り時間を計算し、キューに再び追加
        } else {
            time += q;
            tmp.second -= q;
            p.push(tmp);
        }
    }

    return 0;
}