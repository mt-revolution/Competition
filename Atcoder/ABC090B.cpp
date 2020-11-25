#include<bits/stdc++.h>

using namespace std;



int main() {
	int A, B;
	int num;
	int count = 0;
	bool flag = true;
	vector<int> digit;

	cin >> A >> B;

	for (int i = A; i <= B; i++) {
		num = i;
		digit = {};
		flag = true;
		
		while (num > 0) {
			digit.push_back(num%10);
			num /= 10;
		}


		for (int j = 0; j < digit.size()/2+1; j++) {
			if (digit.at(j) != digit.at(digit.size() - 1 - j)) {
				flag = false;
				break;
			}
		}

		if (flag == true) {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}