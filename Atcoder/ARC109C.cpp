#include<bits/stdc++.h>

using namespace std;

long long n,k;
string s;

// べき乗の余り計算
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// 2人が戦った時に勝つ手
char winner(char left, char right) {
    if (left == right) {
        return left;
    }

    if (left == 'R' && right == 'S' || left == 'S' && right == 'R') {
        return 'R';
    }

    if (left == 'R' && right == 'P' || left == 'P' && right == 'R') {
        return 'P';
    }

    if (left == 'S' && right == 'P' || left == 'P' && right == 'S') {
        return 'S';
    }

    return 'N';
}

// 高さi、左端の人の周期の位置がjの組の勝者の手
char rec(long long i, long long j, vector<vector<char>> &dp) {
    // ベースケース
    if (i == 0) {
        return s[j];
    }

    if (dp[i][j] != 'N') {
        return dp[i][j];
    }

    return dp[i][j] = winner(rec(i-1, j, dp), rec(i-1, (j + modpow(2, i-1, n)) % n, dp));
}


int main() {
	cin >> n >> k;
	
	cin >> s;

    // 高さi、左端の人の周期の位置がjの組の勝者の手
    vector<vector<char>> dp(k+1, vector<char>(n, 'N'));
	
	char winner = rec(k, 0, dp);

    cout << winner << endl;
	return 0;
}