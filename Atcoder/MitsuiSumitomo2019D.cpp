#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string S;
    

    cin >> N;
    cin >> S;

    int count = 0;
    bool finished = false;
    int tmp;
    vector<int> digit(3);

    for(int num = 0; num < 1000; num++) {
        tmp = num;
        for(int d = 2; d >= 0; d--) {
            digit[d] = tmp % 10;
            tmp /= 10;
        }

        finished = false;

        for(int i = 0; i < N-2; i++) {
            if(S[i] - '0' == digit[0]) {
                for(int j = i+1; j < N-1; j++) {
                    if(S[j] - '0' == digit[1]) {
                        for(int k = j+1; k < N; k++) {
                            if(S[k] - '0' == digit[2]) {
                                count++;
                                finished = true;
                                break;
                            }
                        }
                        finished = true;
                        break;
                    }
                    if(finished == true) {
                        break;
                    }
                }
                finished = true;
                break;
            }
            if(finished == true) {
                break;
            }
        }
    }

    cout << count << endl;
	return 0;
}