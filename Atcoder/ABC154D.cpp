#include<bits/stdc++.h>

using namespace std;


int main() {
    int N,K;
    cin >> N >> K;

    double p,p_E;
    
	vector<double> p_E_sum(N+1, 0);
    p_E_sum[0] = 0;

    // pの期待値の累積和をとる
    for (int i = 0; i < N; i++) {
        cin >> p;
        p_E = (p+1)/2;
        p_E_sum[i+1] = p_E_sum[i] + p_E;
    }

    double answer = 0.0;

    // 累積和を使って長さKの区間を全探索
    for (int i = 0; i < N-K+1; i++) {
        answer = max(answer, p_E_sum[i+K] - p_E_sum[i]);
    }

    cout << fixed << setprecision(10) << answer << endl;
	return 0;
}