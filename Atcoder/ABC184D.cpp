#include<bits/stdc++.h>

using namespace std;

// メモ化再帰
double rec(int A, int B, int C, vector<vector<vector<double>>> &dp) {
	double sum = (double)(A + B + C);

	// ベースケース、いずれかが100枚になったとき
	if (A == 100 || B == 100 || C == 100) {
		return 0;
	}

	// 既に値が計算されているとき
	if (dp[A][B][C] != -1.0) {
		return dp[A][B][C];
	}

	// 値が計算されていないときは計算して配列に格納
	return dp[A][B][C] = (double)A/sum * (rec(A+1, B, C, dp) + 1) + (double)B/sum * (rec(A, B+1, C, dp) + 1) + (double)C/sum * (rec(A, B, C+1, dp) + 1);
}

int main() {
	int A,B,C;
	cin >> A >> B >> C;
	
	// 金貨がi枚、銀貨がj枚、銅貨がk枚の状態からいずれかを100枚にするための操作の回数の期待値dp[i][j][k]
	vector<vector<vector<double>>> dp(101, vector<vector<double>>(101, vector<double>(101, -1.0)));

	double answer = rec(A, B, C, dp);

	cout << fixed << setprecision(10) << answer << endl;
	return 0;
}