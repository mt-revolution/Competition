#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,m;
    cin >> n;

    vector<int> s(n), l(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> l[i] >> p[i];
    }

    cin >> m;

    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }

    vector<int> answer;

    // メロディーの長さがjのときの得点の最大値dp[j]
    vector<int> dp(401, 0);

    // dp開始
    for(int i = 0; i < n; i++) {    
        for (int j = 0; j <= 400; j++) {      
            for (int x = s[i]; x <= l[i]; x++) {
                if (j + x <= 400) {
                    dp[j+x] = max(dp[j+x], dp[j] + p[i]);
                }
            }
        }         
    }

    for (int k = 0; k < m; k++) {
        if (dp[w[k]] == 0) {
            cout << -1 << endl;
            return 0;
        }
        
        answer.push_back(dp[w[k]]); 
    }

    for (auto i : answer) {
        cout << i << endl;
    }
    
	return 0;
}