#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
	cin >> S;
	
	int Q;
	cin >> Q;

	// 反転か判定
	int reverse_mode = 0;
	int T, F;
	string C;
	string front = "";
	string back = "";
	
	for (int i = 0; i < Q; i++) {
		cin >> T;
		
		// 1なら反転させる
		if (T == 1) {
			reverse_mode = 1 - reverse_mode;
		// 2の場合
		} else {
			cin >> F >> C;

			// 反転していないとき
			if (reverse_mode == 0) {
				if (F == 1) {
					front += C;
				} else {
					back += C;
				}
			// 反転しているとき
			} else {
				if (F == 1) {
					back += C;
				} else {
					front += C;
				}
			}
		}
	}

	// 最後に文字列に追加する
	S = S + back;
	reverse(S.begin(), S.end());
	S = S + front;
	
	// 最初の並び順のままなら反転させる
	if (reverse_mode == 0) {
		reverse(S.begin(), S.end());
	}

	cout << S << endl;
	return 0;
}