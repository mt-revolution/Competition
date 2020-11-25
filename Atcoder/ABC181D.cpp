#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
    cin >> S;

    int S_size = S.size();
    vector<int> id(10, 0);

    for (int i = 0; i < S_size; i++) {
        if (id[S[i] - '0'] > 3) {
            continue;
        }

        id[S[i] - '0']++;
    }

    vector<int> digit;

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j < id[i]; j++) {
            digit.push_back(i);
        }
    }

    int digit_size = digit.size();
    string num_s;
    int num;

    if (digit_size < 3) {
        do {
            num_s = "";
            for (int i = 0; i < digit_size; i++) {
                num_s += to_string(digit[i]);
            }
            num = stoi(num_s);

            if (num % 8 == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        } while(next_permutation(digit.begin(), digit.end()));
    } else {
        for (int i = 0; i < digit_size-2; i++) {
            for (int j = i+1; j < digit_size-1; j++) {
                for (int k = j+1; k < digit_size; k++) {
                    vector<int> p;
                    p.push_back(digit[i]);
                    p.push_back(digit[j]);
                    p.push_back(digit[k]);
                    do {
                        num_s = "";
                        for (int i = 0; i < 3; i++) {
                            num_s += to_string(p[i]);
                        }
                        num = stoi(num_s);
                        
                        if (num % 8 == 0) {
                            cout << "Yes" << endl;
                            return 0;
                        }

                    } while(next_permutation(p.begin(), p.end()));
                }
            }
        }
    }
   
    cout << "No" << endl;
	return 0;
}