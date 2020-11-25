#include<bits/stdc++.h>

using namespace std;

int main() {
	int A,B;
    int H,M;

    cin >> A >> B >> H >> M;

    double theta_h = 30*H + 0.5*M;
    double theta_m = 6*M;

    double theta = abs(theta_h - theta_m);

    theta = theta*M_PI/180.0;

    double answer = sqrt(A*A + B*B - 2*A*B*cos(theta));

    cout << fixed << setprecision(10) << answer << endl;
	return 0;
}