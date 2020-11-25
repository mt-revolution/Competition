#include<bits/stdc++.h>

using namespace std;

int main() {
	double a,b,x;
    cin >> a >> b >> x;
    double answer;
    const double PI = 3.14159265358979323846;

    if (x == a * a * b) {
        answer = 0;
    } else {
        if(a * a * b / 2.0 <= x) {
            answer = atan(2 * (a * a * b - x) / (a * a * a)) * 180.0 / PI;
        } else {
            answer = (PI / 2 - atan(2 * x / (a * b * b))) * 180.0 / PI;
        }
    }

    cout << fixed << setprecision(10) << answer << endl;
	return 0;
}