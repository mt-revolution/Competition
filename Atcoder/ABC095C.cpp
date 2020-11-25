#include<bits/stdc++.h>

using namespace std;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    int min_sum = 2000000000;
    int x, y;

    for(int i = 0; i <= 2*max(X, Y); i += 2) {
        x = X-i/2;
        y = Y-i/2;
        if(x <= 0) {
            x = 0;       
        } 
        if(y <= 0) {
            y = 0;
        }
        min_sum = min(min_sum, A*x + B*y + C*i);
    }

    cout << min_sum << endl;
	return 0;
}