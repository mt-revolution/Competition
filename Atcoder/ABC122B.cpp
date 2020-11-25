#include<bits/stdc++.h>

using namespace std;

int main() {
    string S;
    string sub_S;

    cin >> S;
    
    int max_size = 0;
    int S_size = S.size();
    int sub_S_size;

    for(int i = 0; i < S_size; i++) {
        sub_S = "";
        for(int j = i; j < S_size; j++) {
            if(S[j] != 'A' && S[j] != 'C' && S[j] != 'G' && S[j] != 'T') {
                break;
            }
            sub_S += S[j];
        }
        sub_S_size = sub_S.size();
        max_size = max(max_size, sub_S_size);       
    }

    cout << max_size << endl;
	return 0;
}