#include<bits/stdc++.h>

using namespace std;

// n個からk個選ぶ組み合わせの場合の数nCk(nが大きいとオーバーフローする)
long long comb(int n, int r) {
    vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
        v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v[n][r];
}


int main() {
  long long L;
  cin >> L;

  // (L-1)C(12-1)を求める
  cout << comb(L-1, 11) << endl;
  return 0;
}