#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> count(N+1, 0);
    int result = 0;

    for(int i = 1; i < N+1; i++) {
        for(int j = i; j < N+1; j += i) {
            count[j]++;
        }
    }

    for(int i = 1; i < N+1; i++) {
        if(i % 2 == 1) {
            if(count[i] == 8) {
                result++;
            }
        }
    }

    cout << result << endl;
	return 0;
}