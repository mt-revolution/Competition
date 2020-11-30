#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> G(n+1, vector<int>(n+1, 0));

    int u,v,k;

    for (int i = 0; i < n; i++) {
        cin >> u >> k;

        for (int i = 0; i < k; i++) {
            cin >> v;
            G[u][v] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == 1) {
                cout << G[i][j];
                continue;
            }
            cout << " " << G[i][j];
        }
        cout << endl;
    }
    
    return 0;
}