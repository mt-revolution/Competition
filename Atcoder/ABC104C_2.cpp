#include<bits/stdc++.h>

using namespace std;

// 整数値のa/bの切り上げ値を求める
int int_ceil(int a, int b) {
	return (a+(b-1))/b;
}

int main() {
	int D,G;
	cin >> D >> G;
	
	vector<int> p(D), c(D);

	for (int i = 0; i < D; i++) {
		cin >> p[i] >> c[i];
	}

	int current_score, count, answer = 1000000000;

	// どの問題を全て解くかbit全探索
    for (int biti = 0; biti < (1<<D); biti++) {
        current_score = 0;
        count = 0;

        for (int i = 0; i < D; i++) {
            if (biti & (1<<i)) {
                count += p[i];
                current_score += 100*(i+1)*p[i] + c[i];
            }
        }

        // G以上になっているとき
        if (current_score >= G) {
            answer = min(answer, count);
            continue;
        }

        // 残り1つだけ残っている一番点数が高い問題を解く
        for (int i = D-1; i >= 0; i--) {
            if (!(biti & (1<<i))) {
                // 見ている問題を全て解き終わる前にG以上になるとき
                if (current_score + 100*(i+1)*p[i] >= G) {
                    count += int_ceil(G - current_score, 100*(i+1));
                    answer = min(answer, count); 
                }

                break;
            }
        }
    }
    
	cout << answer << endl;
	return 0;
}