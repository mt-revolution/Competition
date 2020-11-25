#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> c(n);
	vector<vector<bool>> pole(5001, vector<bool>(5001, false));
	pair<int, int> tmp_3, tmp_4;

	int max_S = 0;

	for(int i = 0; i < n; i++) {
		cin >> c[i].first;
		cin >> c[i].second;
		pole[c[i].first][c[i].second] = true;
	}

	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			tmp_3.first = c[j].first - c[j].second + c[i].second;
			tmp_3.second = c[j].second + c[j].first - c[i].first;
			tmp_4.first = c[i].first - c[j].second + c[i].second;
			tmp_4.second = c[i].second + c[j].first - c[i].first;

			if(tmp_3.first < 0 || tmp_3.first > 5000 || tmp_3.second < 0 || tmp_3.second > 5000 || tmp_4.first < 0 || tmp_4.first > 5000 || tmp_4.second < 0 || tmp_4.second > 5000) {
				continue;
			}

			if(pole[tmp_3.first][tmp_3.second] == true && pole[tmp_4.first][tmp_4.second] == true) {
				max_S = max(max_S, (c[i].first - c[j].first) * (c[i].first - c[j].first) + (c[i].second - c[j].second) * (c[i].second - c[j].second));
			}			
		}
	}

	cout << max_S << endl;
	return 0;
}