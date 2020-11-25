#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    
    long long count = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; i*j < N; j++) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}