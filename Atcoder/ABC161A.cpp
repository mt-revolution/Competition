#include<bits/stdc++.h>

using namespace std;

int main() {
	int X,Y,Z;
	cin >> X >> Y >> Z;

	swap(X,Y);
	swap(X,Z);
	cout << X << " " << Y << " " << Z << endl;
	return 0;
}