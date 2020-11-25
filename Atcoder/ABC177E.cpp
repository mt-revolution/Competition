#include<bits/stdc++.h>
 
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

 
int main() {
    int N;
    cin >> N;

    vector<int> A(N);

	// 素因数分解
    vector<int> prime(1000001, 0);
    int tmp, count;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        prime[A[i]]++;
    }

    bool flag = true;
    for (int i = 2; i <= 1000000; i++) {
        int count = 0;

        for (int j = i; j <= 1000000; j += i) {
            count += prime[j];
        }

        if (count > 1) {
            flag = false;
            break;
        }
    }

    if (flag == true) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    int gcd_all = 0;

    for (int i = 0; i < N; i++) {
        gcd_all = GCD(gcd_all, A[i]);
    }

    if (gcd_all == 1) {
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;
	return 0;
}