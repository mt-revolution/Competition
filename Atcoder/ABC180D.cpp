#include<bits/stdc++.h>

using namespace std;


int main() {
    long long X,Y,A,B;
    cin >> X >> Y >> A >> B;

    long long answer = 0;

    while (1) {
        if (Y/A < X) {
            break;
        }

        if (A*X >= Y || A*X >= X+B) {
            break;
        }

        X *= A;
        answer++;
    }
    
    answer += (Y-1-X)/B;
    
    cout << answer << endl;
    return 0;
}