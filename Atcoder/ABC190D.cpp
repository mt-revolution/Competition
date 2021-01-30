#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N;
    cin >> N;
    
    long long answer = 0;

    // 等差数列の項数をn、初項をaとしてna = N-n*(n-1)/2となる
    // これを整数a>0としてnの可能な範囲で求めると、1つのaに対してそれぞれ2通りの数列が出来る(1つは初項aの数列、もう1つの数列は、-(a-1)からa-1までの和が0になることから初項を-(a-1)とした数列)
    for (long long n = 1; n * (n+3) <= 2000000000000; n++) {
        if ((N - n*(n-1)/2) % n == 0) {
            if ((N - n*(n-1)/2) / n > 0) {
                answer += 2;
            }
        }
    }

    cout << answer << endl;
	return 0;
}