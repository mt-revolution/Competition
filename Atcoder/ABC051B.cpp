#include<bits/stdc++.h>

using namespace std;

int main() {
	int K,S;
    cin >> K >> S;
    
    int Z;
    long long answer = 0;

    for (int X = 0; X <= K; X++) {
        for (int Y = 0; Y <= K; Y++) {
            Z = S - (X+Y);
            if (Z >= 0 && Z <= K) {
                answer++;
            }
        }
    }

    cout << answer << endl;
	return 0;
}