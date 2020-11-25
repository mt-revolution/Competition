#include<bits/stdc++.h>

using namespace std;

int main() {
	string S;
	string tmp;
	string result = "YES";

	cin >> S;

	int S_size = S.size();

	for (int i = S_size - 1; i >= 0; i--) {
		tmp += S.at(i);

		if (tmp.size() >= 8) {
			result = "NO";
			break;
		}
		else if (tmp == "maerd") {
			tmp = "";
		}
		else if (tmp == "remaerd") {
			tmp = "";
		}
		else if (tmp == "esare") {
			tmp = "";
		}
		else if (tmp == "resare") {
			tmp = "";
		}
	}

	if (tmp != "") {
		result = "NO";
	}

	cout << result << endl;
}