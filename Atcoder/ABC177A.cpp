#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
	int D,T,S;
    cin >> D >> T >> S;
 
    if (S*T >= D) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
	return 0;
}