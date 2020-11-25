#include<bits/stdc++.h>

using namespace std;

struct Sushi {
    // 残りの寿司が1個の皿がi枚、2個の皿がj枚、3個の皿がk枚の状態から寿司を全てなくすのにかかる操作回数の期待値dp[i][j][k]
    vector<vector<vector<double>>> dp;

    Sushi(int N) {
        dp.assign(N+1, vector<vector<double>>(N+1, vector<double>(N+1, -1)));
    };

    // 残りの寿司が1個の皿がi枚、2個の皿がj枚、3個の皿がk枚の状態から寿司を全てなくすのにかかる操作回数の期待値f(i,j,k)
    double f(int N, int i, int j, int k) {
        if (i == 0 && j == 0 && k == 0) {
            return dp[i][j][k] = 0;
        }

        if (i+j+k > N || i < 0 || j < 0 || k < 0) {
            return 0;
        }

        // dpの値が計算済みのときその値を返す
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }

        double tmp = 0;

        tmp += i*f(N, i-1, j, k);
        tmp += j*f(N, i+1, j-1, k);
        tmp += k*f(N, i, j+1, k-1);
        tmp += N;
        tmp *= 1.0/(i+j+k);

        return dp[i][j][k] = tmp;
    }
};

int main() {
	int N;
    cin >> N;

    int a;
    vector<int> count(3, 0);
    for (int i = 1; i <= N; i++) {
        cin >> a;
        count[a-1]++;
    }

    Sushi sushi(N);

    cout << fixed << setprecision(10) << sushi.f(N, count[0], count[1], count[2]) << endl;
	return 0;
}