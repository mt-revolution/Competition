#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    long long answer = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            answer += j;
        }
    }

    cout << answer << endl;
	return 0;
}