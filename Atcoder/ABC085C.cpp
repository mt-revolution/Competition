#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	int Y;
	int x = 0;
	int y = 0;
	int z = 0;
	cin >> N >> Y;

	if (Y / 1000 >= N && Y / 10000 <= N) {
		for (x = 0; x <= N; x++) {
			for (y = 0; y <= N - x; y++) {
				z = N - x - y;
				if (10000 * x + 5000 * y + 1000 * z == Y) {
					goto RESULT;
				}
			}
		}
		x = -1;
		y = -1;
		z = -1;
		goto RESULT;
	}
	else {
		x = -1;
		y = -1;
		z = -1;
		goto RESULT;
	}

RESULT:
	cout << x << " " << y << " " << z << endl;

	return 0;
}