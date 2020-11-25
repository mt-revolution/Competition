#include<bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> x(M);
    vector<int> y(M);
    vector<vector<bool>> friends(N, vector<bool>(N, false));
    vector<int> tmp = {};
    int tmp_size;
    int max_group = 1;
    bool continued = false;

    for(int i = 0; i < M; i++) {
        cin >> x[i] >> y[i];
        friends[x[i]-1][y[i]-1] = true;
    }

    for(int biti = 1; biti < (1<<N); biti++) {
        continued = false;
        tmp = {};
        
        for(int i = 0; i < N; i++) {
            if(biti & (1<<i)) {
                tmp.push_back(i);
            }
        }

        sort(tmp.begin(), tmp.end());
        tmp_size = tmp.size();

        for(int i = 0; i < tmp_size-1; i++) {
            for(int j = i+1; j < tmp_size; j++) {
                if(friends[tmp[i]][tmp[j]] == false) {
                    continued = true;
                    goto COUNT;
                }
            }
        }

        COUNT:
        if(continued == true) {
            continue;
        }

        max_group = max(max_group, tmp_size);
    }

    cout << max_group << endl;
	return 0;
}