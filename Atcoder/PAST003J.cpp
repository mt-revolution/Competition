#include<bits/stdc++.h>

using namespace std;


int main() {
	int N,M;
	cin >> N >> M;
	
	int a;
	// それぞれの人が食べた寿司の最高の美味しさ
	vector<int> max_sushi(N, 0);
	
	for (int i = 0; i < M; i++) {
		cin >> a;
		
		// 二分探索でどの子供がとるのかを探索
		int index = upper_bound(max_sushi.begin(), max_sushi.end(), -a) - max_sushi.begin();

		// どの子供よりも美味しさが小さい寿司の場合
		if (index == N) {
			cout << -1 << endl;
			continue;
		}
		
		max_sushi[index] = -a;
		cout << index+1 << endl;
	}
	return 0;
}