#include<bits/stdc++.h>

using namespace std;

int N;
const int INF = 1000000000;

// 最長増加部分列(LIS)の大きさ
int LIS(vector<int> a) {
	// 最長増加部分列問題の数列の長さがiのときの最終要素の最小値のペアdp[i]
	vector<int> dp(N+1, INF);
	int n = a.size();

	for (int i = 0; i < n; i++) {
		*lower_bound(dp.begin(), dp.begin() + n, a[i]) = a[i];
	}
	return lower_bound(dp.begin(), dp.begin() + n, INF) - dp.begin();
}

// pairのfirstで昇順ソート、firstが同じ場合はsecondで降順ソート
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first < b.first) return true;
	else if (a.first > b.first) return false;
	else if (a.second > b.second) return true;
	else return false;
}

int main() {
	cin >> N;
	
	int w,h;
	vector<pair<int, int>> present(N);
	for (int i = 0; i < N; i++) {
		cin >> w >> h;
		present[i] = make_pair(w, h);
	}

	// wで昇順ソート、hで降順ソート
	sort(present.begin(), present.end(), cmp);

    vector<int> second(N);
	
    for (int i = 0; i < N; i++) {
		second[i] = present[i].second;
	}

	// hについて最長増加部分列(LIS)の大きさを求める
	int answer = LIS(second);

	cout << answer << endl;
	return 0;
}