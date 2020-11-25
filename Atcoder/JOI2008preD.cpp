#include<bits/stdc++.h>

using namespace std;

bool vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
  }
  else { // 発見できなかったとき
    return false;
  }
}

int main() {
    int m, n;

    cin >> m;
    vector<int> s_x(m), s_y(m);
    vector<int> delta_x(m), delta_y(m);
    int count = 0;
    int result_x = 0, result_y = 0;

    for(int i = 0; i < m; i++) {
        cin >> s_x[i] >> s_y[i];
    }

    cin >> n;
    vector<int> p_x(n), p_y(n);

    for(int i = 0; i < n; i++) {
        cin >> p_x[i] >> p_y[i];
    }

    // 探す星座のうちの1点を決めて、そこからの相対距離を測って配列に格納
    for(int i = 0; i < m; i++) {
        delta_x[i] = s_x[i] - s_x[0];
        delta_y[i] = s_y[i] - s_y[0];
    }

    // 写真から星を1点ずつ見て、そこから先ほどの相対距離を使った先に星があるかを調べる
    for(int i = 0; i < n; i++) {
        count = 0;
        for(int j = 0; j < m; j++) {
            if(p_x[i] + delta_x[j] < 0 || p_x[i] + delta_x[j] > 1000000 || p_y[i] + delta_y[j] < 0 || p_y[i] + delta_y[j] > 1000000) {
                break;
            }
            if(vector_finder(p_x, p_x[i] + delta_x[j]) == false || vector_finder(p_y, p_y[i] + delta_y[j]) == false) {
                break;
            } 
            count++;            
        }
        // 全てに星があった場合、結果を保存して終了
        if(count == m) {
            result_x = p_x[i] - s_x[0];
            result_y = p_y[i] - s_y[0];
            break;
        }
    }

    cout << result_x << " " << result_y << endl;
	return 0;
}