#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
    cin >> N;

    int tmp = 0;
    vector<int> light(N+1);

    // 交互列の長さをカウント
    vector<int> sequence;

    sequence.push_back(0);

    cin >> light[1];
    tmp = 1;

    for (int i = 2; i <= N; i++) {
        cin >> light[i];

        if (light[i] != light[i-1]) {
            tmp += 1;
        } else {
            sequence.push_back(tmp);
            tmp = 1;
        }
    }

    sequence.push_back(tmp);
    sequence.push_back(0);
    
    int answer = 0;

    for (int i = 0; i < sequence.size() - 2; i++) {
        answer = max(answer, sequence[i] + sequence[i+1] + sequence[i+2]);
    }

    cout << answer << endl;
	return 0;
}