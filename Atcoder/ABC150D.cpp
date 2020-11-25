#include<bits/stdc++.h>

using namespace std;

// 最小公倍数
long long lcm(long long a, long long b) {
    return a * b / __gcd(a, b);
}

int main() {
    int N;
	long long M;
    cin >> N >> M;

    long long lcm_all = 1;
    long long count = 0;
    long long tmp = 1;

    vector<long long> a(N);
    long long a_tmp = 0, min_tmp = 1000000000;

    for (int i = 0; i < N; i++) {
        cin >> a_tmp;
        a[i] = a_tmp;
        tmp = 1;

        while (a_tmp % 2 == 0) {
            a_tmp /= 2;
            tmp *= 2;
        }

        min_tmp = min(min_tmp, tmp);
    }

    for (int i = 0; i < N; i++) {
        a[i] /= min_tmp;
        lcm_all = lcm(lcm_all, a[i]);
    }



    if (lcm_all % 2 == 0) {
        // 半公倍数が存在する場合
        if (M >= lcm_all / 2) {
            count = (M - lcm_all / 2) / lcm_all + 1;
        }
    }
    
    cout << count << endl;
	return 0;
}