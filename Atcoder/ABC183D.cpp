#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    long long W;
    cin >> N >> W;
    
    int S,T;
    long long P;

    vector<long long> table(200001, 0);
    for (int i = 0; i < N; i++) {
        cin >> S >> T >> P;
        table[S] += P;
        table[T] -= P;
    }

    for (int i = 1; i <= 200000; i++) {
        table[i] += table[i-1];
    }

    for (int i = 0; i <= 200000; i++) {
        if (table[i] > W) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
	return 0;
}