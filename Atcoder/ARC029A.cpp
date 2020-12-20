#include<bits/stdc++.h>

using namespace std;


int main() {
	int N;
    cin >> N;
    
    vector<int> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }

    int count_0, count_1, answer = 1000000000;

    for (int biti = 0; biti < (1<<N); biti++) {
        count_0 = 0, count_1 = 0;

        for (int i = 0; i < N; i++) {
            if (biti & (1<<i)) {
                count_0 += t[i];
            } else {
                count_1 += t[i];
            }
        }

        answer = min(answer, max(count_0, count_1));
    }

    cout << answer << endl;
	return 0;
}