#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<vector<int>> a(N, vector<int>(N, 0));
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> digit(N, 0);
	int answer = -1000000000;
	vector<vector<int>> group(3, vector<int>{});
	int count;
	int group_size;
	int tmp;

	for (int mask = 0; mask < pow(3, N); mask++) {
		tmp = mask;
		digit.assign(N, 0);
		group.assign(3, vector<int>{});
		count = 0;

		for (int pos = 0; pos < N; pos++) {
			digit[pos] = tmp % 3;
			tmp /= 3;

			group[digit[pos]].push_back(pos);
		}

		

		for (int k = 0; k < 3; k++) {
			group_size = group[k].size();

			if (group_size >= 2) {
				for (int i = 0; i < group_size-1; i++) {
					for (int j = i+1; j < group_size; j++) {
						count += a[group[k][i]][group[k][j]];
					}
				}
			}
		}

		answer = max(answer, count);
	}

	cout << answer << endl;
	return 0;
}