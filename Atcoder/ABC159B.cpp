#include<bits/stdc++.h>

using namespace std;

// 回文判定
bool is_palindrome(string S) {
    int N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] != S[N-1-i]) {
            return false;
        }
    }

    return true;
}

int main() {
	string S;
	cin >> S;
	
	int N = S.size();

	string S_1 = S.substr(0, (N-1)/2);
	string S_2 = S.substr((N+3)/2-1, (N-1)/2);

	if (is_palindrome(S) == true && is_palindrome(S_1) == true && is_palindrome(S_2) == true) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}