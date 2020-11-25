#include<bits/stdc++.h>

using namespace std;

int main() {
	long long N;
    cin >> N;

    // Nを26進数に直した各桁の数
    vector<long long> alphabet;

    // 各桁の数を求める
    while (N != 0) {
        N -= 1;
        alphabet.insert(alphabet.begin(), N % 26);
        N /= 26;
    }

    string answer = "";

    // 各桁の数からアルファベットに復元
    for (auto i : alphabet) {
        answer += 'a' + i;
    }

    cout << answer << endl;
	return 0;
}