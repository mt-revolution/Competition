#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
	cin >> N;
	
	int A,B;

	vector<priority_queue<int>> day(N+1);

	// 日ごとにタスクをまとめる
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		day[A].push(B);
	}

	int tmp;
	int answer = 0;

	// 全体のタスクの優先度つきキュー
	priority_queue<int> task_list;

	for (int k = 1; k <= N; k++) {
		// 日ごとのタスクを全体のタスクに入れる
		while (day[k].empty() == false) {
			tmp = day[k].top();
			day[k].pop();
			task_list.push(tmp);
		}

		// ポイント最大のタスク(先頭)を取り出す
		answer += task_list.top();
		task_list.pop();
		cout << answer << endl;
	}

	return 0;
}