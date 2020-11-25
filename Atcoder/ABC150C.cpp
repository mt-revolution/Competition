#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    vector<int> P(N), Q(N);
    int count = 0;
    int a, b;

    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    for(int i = 1; i <= N; i++) {
        v[i-1] = i;
    }

    do {
        count++;
        if(P == v) {
            a = count;
        }
        if(Q == v) {
            b = count;
        }
    } while(next_permutation(v.begin(), v.end()));

    cout << abs(a - b) << endl;    
    return 0;
}