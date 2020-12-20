#include<bits/stdc++.h>

using namespace std;

int main() {
	int N,Y;
	cin >> N >> Y;
	
	int z;
	
	for (int x = 0; x <= 2000; x++) {
		for (int y = 0; y <= 4000; y++) {
			z = N - (x+y);

			if (z >= 0 && 1000*z == Y - (10000*x + 5000*y)) {
				cout << x << " " << y << " " << z << endl;
				return 0;
			}
		}
	}

	cout << -1 << " " << -1 << " " << -1 << endl;
	return 0;
}