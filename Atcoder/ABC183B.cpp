#include<bits/stdc++.h>

using namespace std;

int main() {
	double s_x, s_y, g_x, g_y;
	cin >> s_x >> s_y >> g_x >> g_y;

	s_y = -s_y;

	double x = -s_y*(g_x-s_x)/(g_y-s_y)+s_x;

    cout << fixed << setprecision(10) << x << endl;
	return 0;
}