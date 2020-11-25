#include<bits/stdc++.h>

using namespace std;

int main() {
	int K;
	cin >> K;
	
	vector<long long> lunlun, digit_tmp, tmp;

	lunlun.push_back(0);
	long long d;

	// 初期条件(ルンルン数と桁ごとのルンルン数を格納)
	for (int i = 1; i <= 9; i++) {
		lunlun.push_back(i);
		digit_tmp.push_back(i);
	}

	int count = 9;

	while(1) {
		// 前の桁ごとのルンルン数を取り出す
		tmp = digit_tmp;
		// 今の桁ごとのルンルン数を空にして追加していく
		digit_tmp.assign({});

		for (auto num : tmp) {
			for (long long i = -1; i <= 1; i++) {
				d = num%10 + i;

				if (d >= 0 && d <= 9) {
					digit_tmp.push_back(num*10 + d);
					lunlun.push_back(num*10 + d);
					count++;

					// 終了条件
					if (count > K) {
						cout << lunlun[K] << endl;
						return 0;
					}
				}
			}	
		}
	}

	return 0;
}