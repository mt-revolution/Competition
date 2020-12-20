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
	// 順列用
	vector<int> per;

	for (int i = 0; i < D; i++) {
		cin >> p[i] >> c[i];
		per.push_back(i);
	}

	int current_score, count, answer = 1000000000;

	// どの順番で問題を解いていくか順列全探索
	do {
		current_score = 0;
		count = 0;

		for (auto i : per) {
			// 見ている問題を全て解き終わる前にG以上になるとき
			if (current_score + 100*(i+1)*p[i] >= G) {
				count += int_ceil(G - current_score, 100*(i+1));
				answer = min(answer, count);
				break;
			// 見ている問題を全て解き終わってボーナスをもらったときにG以上になるとき
			} else if (current_score + 100*(i+1)*p[i] + c[i] >= G) {
				count += p[i];
				answer = min(answer, count);
				break;
			// 見ている問題を全て解き終わってボーナスをもらってもまだG以上にならないとき
			} else {
				count += p[i];
				current_score += 100*(i+1)*p[i] + c[i];
			}
		}
	} while(next_permutation(per.begin(), per.end()));
    
	cout << answer << endl;
	return 0;
}