#include<bits/stdc++.h>

using namespace std;


int main() {
    long long A,B,X;
    cin >> A >> B >> X;
    
    // 条件を満たさない一番小さい数
    long long right = 1000000001;
    // 条件を満たす一番大きい数
    long long left = 0;

    long long mid;
    long long d;
    
    // 二分探索
    while (right - left > 1) {
        mid = (right + left)/2;
        d = to_string(mid).size();

        if (A * mid + B * d <= X) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << left << endl;    
	return 0;
}