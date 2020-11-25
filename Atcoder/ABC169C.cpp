#include<bits/stdc++.h>

using namespace std;

int main() {
    long long A;
    double B;
    long long answer;
    cin >> A >> B;

    // Bを100倍して整数で扱う
    long long lB = round(B*100);
    // 100で割ると小数点以下が切り捨てられる
    answer = A*lB/100;

    cout << answer << endl;
	return 0;
}