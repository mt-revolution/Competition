#include<bits/stdc++.h>

using namespace std;


int main() {
    stack<long long> num;
    string str;

    long long num1, num2;
    
    // 入力が存在する間続ける
    while (cin >> str) {
        // 符号が入力されたとき
        if (str == "+") {
            num1 = num.top();
            num.pop();
            num2 = num.top();
            num.pop();
            num.push(num2 + num1);
        } else if (str == "-") {
            num1 = num.top();
            num.pop();
            num2 = num.top();
            num.pop();
            num.push(num2 - num1);
        } else if (str == "*") {
            num1 = num.top();
            num.pop();
            num2 = num.top();
            num.pop();
            num.push(num2 * num1);
        // 数字が入力されたとき
        } else {
            num.push(stoll(str));
        }
    }

    // 残った数を出力
    long long answer = num.top();
    cout << answer << endl;
    return 0;
}