#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N;
    cin >> N;
    
    long long X,Y;
    long long answer = 1000000000000000000;
    
    for (long long i = 1; i*i <= N; i++) {
        if (N % i == 0) {
            X = i;
            Y = N/i;
            answer = min(answer, X-1 + Y-1);
        }
    }

    cout << answer << endl;
	return 0;
}