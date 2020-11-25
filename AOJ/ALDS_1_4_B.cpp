#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,q;

    cin >> n;
    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    cin >> q;
    vector<int> T(q);

    for (int i = 0; i < q; i++) {
        cin >> T[i];
    }

    int count = 0;

    for (int i = 0; i < q; i++) {
        auto iter = lower_bound(S.begin(), S.end(), T[i]);

        if (*iter == T[i]) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}