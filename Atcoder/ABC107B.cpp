#include<bits/stdc++.h>

using namespace std;

int main() {
    int H,W;
    cin >> H >> W;
    char tmp;
    int count = 0;
    int finished = 0;

    vector<string> a(H);

    for (int i = 0; i < H; i++) {
		cin >> a.at(i);
	}

    do {
        finished = 0;
        for(int i = 0; i < H; i++) {
            count = 0;
            for(int j = 0; j < W; j++) {
                if(a[i][j] == '.') {
                    count++;
                }
            }

            if(count == W) {
                a.erase(a.begin() + i);
                finished = 1;
                H -= 1;
            }
        }

        for(int i = 0; i < W; i++) {
            count = 0;
            for(int j = 0; j < H; j++) {
                if(a[j][i] == '.') {
                    count++;
                }
            }

            if(count == H) {
                for(int j = 0; j < H; j++) {
                    a[j].erase(a[j].begin() + i);
                }
                finished = 1;
                W -= 1;
            }
        }

    } while(finished != 0);

    for (int i = 0; i < H; i++) {
		cout << a.at(i) << endl;
	}

	return 0;
}