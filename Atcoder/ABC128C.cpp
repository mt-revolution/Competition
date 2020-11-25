#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> k(M);
    vector<vector<int>> s;
    vector<int> p(M);
    int switch_count = 0;
    int light_count = 0;
    int result_count = 0;

    for(int i = 0; i < M; i++) {
        cin >> k[i];
        vector<int> tmp(k[i]); 
        for(int j = 0; j < k[i]; j++) {
            cin >> tmp[j];
        }
        s.push_back(tmp);
    }

    for(int i = 0; i < M; i++) {
        cin >> p[i];
    }

    for(int biti = 0; biti < (1<<N); biti++) {
        light_count = 0;

        for(int j = 0; j < M; j++) {
            switch_count = 0;

            for(int l : s[j]) {
                if(biti & (1<<(l-1))) {
                    switch_count++;
                }
            }

            if(switch_count % 2 == p[j]) {
                light_count++;
            }
        }

        if(light_count == M) {
            result_count++;
        }
    }

    cout << result_count << endl;
	return 0;
}