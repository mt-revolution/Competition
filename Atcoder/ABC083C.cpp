#include<bits/stdc++.h>

using namespace std;

int main() {
	long long X,Y;
    cin >> X >> Y;
    
    long long answer = 1;
    while (1) {
        if (X * 2 > Y) {
            break;
        }
        
        X *= 2;
        answer++;
    }

    cout << answer << endl;
	return 0;
}