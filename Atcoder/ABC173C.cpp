#include<bits/stdc++.h>

using namespace std;

int main() {
	int H, W, K;
	cin >> H >> W >> K;

	vector<vector<char>> c(H, vector<char>(W));
	int count = 0;
	int result = 0;

	for(int i = 0; i < H; i++) {
		for(int j = 0; j < W; j++) {
			cin >> c.at(i).at(j);
		}
	}

	for(int biti = 0; biti < (1<<H); biti++) {
		for(int bitj = 0; bitj < (1<<W); bitj++) {
			count = 0;
			for(int i = 0; i < H; i++) {
				for(int j = 0; j < W; j++) {
					if(!(biti & (1<<i)) || !(bitj & (1<<j))) {
						continue;
					}
					if(c.at(i).at(j) == '#') {
						count++;
					}
				}
			}
			if(count == K) {
				result++;
			}
		}
	}

	cout << result << endl;
	return 0;
}