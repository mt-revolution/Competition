#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    double W;
    cin >> N >> W;
    
    // 価値/重さ、価値、重さのtuple
    vector<tuple<double, int, int>> items(N);

    int v,w;
    double c;

    for (int i = 0; i < N; i++) {
        cin >> v >> w;
        c = (double)v / (double)w;
        items[i] = make_tuple(c, v, w);
    }

    // 価値/重さで降順ソート
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());

    double answer = 0;

    // 重さがWに達するまで順に詰め込んでいく
    for (int i = 0; i < N; i++) {
        tie(c, v, w) = items[i];
        
        answer += c * min((double)w, W);
        W -= min((double)w, W);

        if (W == 0) {
            break;
        }
    }
    
    cout << fixed << setprecision(10) << answer << endl;
	return 0;
}