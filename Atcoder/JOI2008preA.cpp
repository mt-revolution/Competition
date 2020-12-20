#include<bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    
    int change = 1000 - N;
    vector<int> coin = {500, 100, 50, 10, 5, 1};
    int answer = 0;

    for (auto i : coin) {
        answer += change / i;
        change %= i;
    }

    cout << answer << endl;
	return 0;
}