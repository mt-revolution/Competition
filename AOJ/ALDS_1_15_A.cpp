#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    int answer = 0;

    vector<int> coin = {25, 10, 5, 1};

    int tmp = n;

    for (auto cent : coin) {
        answer += tmp / cent;
        tmp -= cent * (tmp / cent);
    }

    cout << answer << endl;
	return 0;
}