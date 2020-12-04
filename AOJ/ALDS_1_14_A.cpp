#include<bits/stdc++.h>

using namespace std;


int main() {
    string T, P;
    cin >> T;
    cin >> P;
    
    int T_size = T.size(), P_size = P.size();

    for (int i = 0; i <= T_size - P_size; i++) {
        if (T.substr(i, P_size) == P) {
            cout << i << endl;
        }
    }

	return 0;
}