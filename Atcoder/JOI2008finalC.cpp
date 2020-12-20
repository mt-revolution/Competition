#include<bits/stdc++.h>

using namespace std;

int main() {
	int N, M;

	cin >> N >> M;
	vector<int> P(N+1);

	int current_point = 0;
	int max_point = 0;

	for(int i = 0; i < N; i++) {
		cin >> P[i];
	}

	// ダーツを投げなかった場合
	P[N] = 0;

	sort(P.begin(), P.end());

	// ダーツを2回まとめて投げた場合の得点
	vector<int> P_twice = {};

	for(int i = 0; i < N+1; i++) {
		for(int j = 0; j < N+1; j++) {
			P_twice.push_back(P[i] + P[j]);
		}
	}

	sort(P_twice.begin(), P_twice.end());

	auto iter1 = upper_bound(P_twice.begin(), P_twice.end(), M);

	// 半分全列挙
	for(auto iteri = P_twice.begin(); iteri < iter1; iteri++) {
		current_point = *iteri;
		if(current_point <= M) {
			max_point = max(max_point, current_point);
		}

		auto iter2 = upper_bound(P_twice.begin(), P_twice.end(), M - current_point);

		// 2分探索してMを超えない最大の得点を足す
		current_point = *iteri + *(iter2-1);
		if(current_point <= M) {
			max_point = max(max_point, current_point);
		}
	}

	cout << max_point << endl;	
	return 0;
}