#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
    long long D;
	cin >> N >> D;

	int I = 0, J = 0, K = 0;

	// 2,3,5の乗数を記録し、それ以外の因数があれば確率0
	while (D % 2 == 0) {
		I++;
		D /= 2;
	}

	while (D % 3 == 0) {
		J++;
		D /= 3;
	}

	while (D % 5 == 0) {
		K++;
		D /= 5;
	}

	if (D != 1) {
		cout << 0 << endl;
		return 0;
	}

	// i回サイコロをふったときにx回2が、y回3が、z回5が積に含まれている確率dp[i][x][y][z]
	vector<vector<vector<vector<double>>>> dp(N+1, vector<vector<vector<double>>>(I+1, vector<vector<double>>(J+1, vector<double>(K+1, 0.0))));
	
	// 初期条件
	dp[0][0][0][0] = 1;

	// 各さいころの目のx,y,z(2,3,5)の増分
	vector<int> inc_x = {0, 1, 0, 2, 0, 1};
	vector<int> inc_y = {0, 0, 1, 0, 0, 1};
	vector<int> inc_z = {0, 0, 0, 0, 1, 0};

	int next_x, next_y, next_z;

	// dp開始
	for (int i = 0; i < N; i++) {
		for (int x = 0; x <= I; x++) {
			for (int y = 0; y <= J; y++) {
				for (int z = 0; z <= K; z++) {
					for (int k = 0; k < 6; k++) {
						next_x = min(I, x + inc_x[k]);
						next_y = min(J, y + inc_y[k]);
						next_z = min(K, z + inc_z[k]);
						dp[i+1][next_x][next_y][next_z] += dp[i][x][y][z] / 6.0;
					}
				}
			}
		}
	}

	double answer = dp[N][I][J][K];
	cout << fixed << setprecision(10) << answer << endl;
	return 0;
}