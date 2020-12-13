#include<bits/stdc++.h>

using namespace std;

// 勝つ手
char win(char c) {
    if (c == 'r') {
        return 'p';
    } else if (c == 's') {
        return 'r';
    } else {
        return 's';
    }
}

int main() {
    int N,K;
    cin >> N >> K;
    
    map<char, int> point;
    cin >> point['r'] >> point['s'] >> point['p'];

    string T;
    cin >> T;

    int len_T = T.size();
    
    int answer = 0;
    string tmp = "";

    for (int i = 0; i < len_T; i++) {
        // i<Kは勝つ手を出す
        if (i < K) {
            tmp += win(T[i]);
            answer += point[win(T[i])];
        // i < len_T - Kは勝つ手をi-Kで既に出しているときはその手とi+Kで勝つ手以外の手を出す、出していなければその手を出す
        } else if (i + K < len_T) {
            if (win(T[i]) == tmp[i-K]) {
                if (win(T[i]) == 'r') {
                    if (win(T[i+K]) == 's') {
                        tmp += 'p';
                    } else if (win(T[i+K]) == 'p') {
                        tmp += 's';
                    } else {
                        tmp += 's';
                    }
                } else if (win(T[i]) == 's') {
                    if (win(T[i+K]) == 'r') {
                        tmp += 'p';
                    } else if (win(T[i+K]) == 'p') {
                        tmp += 'r';
                    } else {
                        tmp += 'r';
                    }
                } else {
                    if (win(T[i+K]) == 's') {
                        tmp += 'r';
                    } else if (win(T[i+K]) == 'r') {
                        tmp += 's';
                    } else {
                        tmp += 's';
                    }
                }
            } else {
                tmp += win(T[i]);
                answer += point[win(T[i])];
            }
        // i >= len_T + Kは勝つ手をi-Kで既に出しているときは出さない、出していなければその手を出す
        } else {
            if (win(T[i]) == tmp[i-K]) {
                tmp += 'r';
            } else {
                tmp += win(T[i]);
                answer += point[win(T[i])];
            }
        }  
    }

    cout << answer << endl;
	return 0;
}