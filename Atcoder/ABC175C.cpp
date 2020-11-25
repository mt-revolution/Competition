#include<bits/stdc++.h>

using namespace std;

int main() {
	long long X, K, D;
	cin >> X >> K >> D;

	long long answer, tmp;

	X = abs(X);
	// Xから0に一番近づくまで何回移動すれば良いか調べる
	tmp = X / D;

	// K回で足りない場合
	if(tmp >= K) {
		answer = X - K*D;
	
	// K回で足りる場合
	} else {
		// 残りの無駄な移動の回数が偶数回なら往復を繰り返す
		if((K - tmp) % 2 == 0) {
			answer = X - tmp*D;
			
		// 残りの無駄な移動の回数が奇数回なら1回だけ正か負の0に近い方に動く
		} else {
			answer = min(abs(X - tmp*D + D), abs(X - tmp*D - D));
		}
	}	

	cout << answer << endl;
	return 0;
}