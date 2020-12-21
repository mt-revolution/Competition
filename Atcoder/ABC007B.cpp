#include<bits/stdc++.h>

using namespace std;

int main() {
	string A;
    cin >> A;
    
    // Aがaの場合
    if (A == "a") {
        cout << -1 << endl;
    } else {
        // Aが1文字より大きい場合末尾を省略して出力
        if (A.size() > 1) {
            for (int i = 0; i < A.size()-1; i++) {
                cout << A[i];
            }
            cout << endl;
        // Aが1文字の場合先頭を1文字戻して出力
        } else {
            A[0]--;
            cout << A << endl;
        }
    }
	return 0;
}