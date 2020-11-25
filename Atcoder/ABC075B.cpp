#include<bits/stdc++.h>

using namespace std;


int main() {
	int H, W;
	int x, y;
	vector<int> delta_x{-1, -1, -1, 0, 0, 1, 1, 1};
	vector<int> delta_y{1, 0, -1, 1, -1, 1, 0, -1};

	cin >> H >> W;

	vector<string> S(H);
	for (int i = 0; i < H; i++) {
		cin >> S.at(i);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S.at(i).at(j) == '.') {
				S.at(i).at(j) = '0';
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (S.at(i).at(j) == '#') {
				for (int k = 0; k < 8; k++) {
					x = i + delta_x.at(k);
					y = j + delta_y.at(k);

					if (x >= 0 && y >= 0 && x < H && y < W && S.at(x).at(y) != '#') {
						S.at(x).at(y) += 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < H; i++) {
		cout << S.at(i) << endl;
	}
	
	return 0;
}