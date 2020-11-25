#include<bits/stdc++.h>

using namespace std;


int main() {
	long long S,P;
    cin >> S >> P;

    long long j;
    
    for (long long i = 1; i*i <= P; i++) {
        j = S-i;
        if (i*j == P) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
	return 0;
}