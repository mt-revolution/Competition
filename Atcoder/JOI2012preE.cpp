#include<bits/stdc++.h>

using namespace std;

int W, H;

int main() {
    cin >> W >> H;

    vector<vector<int>> field(H+2, vector<int>(W+2, 0));
    vector<vector<bool>> blank(H+2, vector<bool>(W+2, false));
    vector<vector<int>> border_count(H+2, vector<int>(W+2, 0));
    queue<pair<int, int>> checked;
    int count = 0;

    vector<int> delta_i{0, 0, 1, 1, -1, -1};
    vector<int> delta_j_odd{-1, 1, 0, 1, 0, 1};
    vector<int> delta_j_even{-1, 1, -1, 0, -1, 0};

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            cin >> field[i][j];
        }
    }    

    // 外側の余白を調べ、建物がある境界の長さをそれぞれ計算する
    checked = {};    
    checked.push(pair<int, int>(0, 0));
    blank[0][0] = true;

    while(checked.empty() == false) {
        int i = checked.front().first;
        int j = checked.front().second;
        checked.pop();
        
        if(i % 2 == 1) {
            for(int k = 0; k < 6; k++) {
                if(i + delta_i[k] >= 0 && i + delta_i[k] <= H+1 && j + delta_j_odd[k] >= 0 && j + delta_j_odd[k] <= W+1) {
                    if(field[i + delta_i[k]][j + delta_j_odd[k]] != 1) {
                        if(blank[i + delta_i[k]][j + delta_j_odd[k]] == true) {
                            continue;
                        } else {
                            blank[i + delta_i[k]][j + delta_j_odd[k]] = true;
                            checked.push(pair<int, int>(i + delta_i[k], j + delta_j_odd[k]));
                        }
                    } else {
                        border_count[i][j]++;
                    }
                }                
            }
        } else {
            for(int k = 0; k < 6; k++) {  
                if(i + delta_i[k] >= 0 && i + delta_i[k] <= H+1 && j + delta_j_even[k] >= 0 && j + delta_j_even[k] <= W+1) {              
                    if(field[i + delta_i[k]][j + delta_j_even[k]] != 1) {
                        if(blank[i + delta_i[k]][j + delta_j_even[k]] == true) {
                            continue;
                        } else {
                            blank[i + delta_i[k]][j + delta_j_even[k]] = true;
                            checked.push(pair<int, int>(i + delta_i[k], j + delta_j_even[k]));
                        }
                    } else {
                        border_count[i][j]++;
                    }
                }
            }
        }
    }

    // それぞれの境界の長さを全て足す
    for(int i = 0; i < H+2; i++) {
        for(int j = 0; j < W+2; j++) {
            if(blank[i][j] == true) {
                count += border_count[i][j];
            }
        }
    }

    cout << count << endl;
	return 0;
}