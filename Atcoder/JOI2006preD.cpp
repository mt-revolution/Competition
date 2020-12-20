#include<bits/stdc++.h>

using namespace std;

int main() {
	int n,m;
    cin >> n >> m;
    
    int answer = 0;
    int k, num;
    vector<int> v(n);

    for (int i = 0; i < 3; i++) {
        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> num;
            v[n-num] = i;
        }
    }

    int p = 0;
    int d;
    for (int i = n-1; i >= 0; i--) {
        d = abs(v[i] - p);
        answer += pow(3, i)*d;
        if (d == 1) {
            p = 2-p;
        }
    }

    answer = min(answer, (int)pow(3,n) - 1 - answer);
    
    if (answer <= m) {
        cout << answer << endl;
    } else {
        cout << -1 << endl;
    }
	return 0;
}