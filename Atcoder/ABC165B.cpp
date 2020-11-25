#include<bits/stdc++.h>

using namespace std;

int main() {
	long long X;
	cin >> X;
	
	long long current_money = 100;
	int answer;
	
	for (int i = 1; ; i++) {
		current_money += current_money / 100;
		
		if (current_money >= X) {
			answer = i;
			break;
		}
	}

	cout << answer << endl;
	return 0;
}