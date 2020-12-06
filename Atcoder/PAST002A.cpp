#include<bits/stdc++.h>

using namespace std;

int floor_number(string s) {
    if (s[0] == 'B') {
        return -(s[1] - '0');
    } else {
        return s[0] - '0' - 1;
    }
}

int main() {
	string S,T;
    cin >> S >> T;
    
    cout << abs(floor_number(S) - floor_number(T)) << endl;
	return 0;
}