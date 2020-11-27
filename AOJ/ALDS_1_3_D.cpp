#include<bits/stdc++.h>

using namespace std;


int main() {
    long long depth = 0;
    // long long sum = 0, S = 0;
    double S = 0.0;
    long long sum = 0;
    vector<long long> S_list;
    char c;

    while (cin >> c) {
        if (c == '\\') {
            S += 0.5;
            S += (double)depth;
            depth += 1;
        } else if (c == '/') {
            if (depth == 0) {
                continue;
            }

            depth -= 1;
            S += 0.5;
            S += (double)depth;
            
            if (depth == 0) {
                S_list.push_back((long long)S);
                sum += (long long)S;
                S = 0.0;
                continue;
            }

        } else if (c == '_') {
            S += (double)depth;
        }
    }

    cout << sum << endl;
    int k = S_list.size();
    cout << k;

    for (int i = 0; i < k; i++) {
        cout << " " << S_list[i];
    }
    return 0;
}