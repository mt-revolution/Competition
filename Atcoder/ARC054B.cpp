#include<bits/stdc++.h>

using namespace std;

int main() {
	double P;
    cin >> P;

    double x, answer;

    x = 3.0/2.0 * log(2.0/3.0 * P * log(2.0)) / log(2.0);

    if(x < 0) {
        x = 0;
    }

    answer = x + P/pow(2.0, 2.0*x/3.0);
    
    cout << fixed << setprecision(10) << answer << endl;
	return 0;
}