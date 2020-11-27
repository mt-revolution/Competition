#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    sort(S.begin(), S.end());

    int q;
    cin >> q;
    
    vector<int> T(q);
    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }

    int answer = 0;

    for (int i = 0; i < q; i++) {
        for (int j = 0; j < n; j++) {
            if (S[j] == T[i]) {
                answer++;
                break;
            }
        }
    }

    
    
    cout << answer << endl;
    return 0;
}