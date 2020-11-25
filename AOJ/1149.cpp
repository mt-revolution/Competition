#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,w,d;

    while (true) {
        cin >> n >> w >> d;

        if (n == 0 && w == 0 && d == 0) {
            break;
        }

        vector<int> p(n), s(n);
        vector<int> area, width, depth;
        int tmp_s, tmp_first, tmp_second, tmp_area, tmp_width, tmp_depth;

        for (int i = 0; i < n; i++) {
            cin >> p[i] >> s[i];
            p[i]--;
        }

        // 初期条件
        width.push_back(w);
        depth.push_back(d);
        area.push_back(w * d);

        for (int i = 0; i < n; i++) {
            // 切るケーキのピースを取り出して削除
            tmp_width = width[p[i]];
            tmp_depth = depth[p[i]];
            tmp_area = area[p[i]];
            width.erase(width.begin() + p[i]);
            depth.erase(depth.begin() + p[i]);
            area.erase(area.begin() + p[i]);

            // どこを切るか判定
            tmp_s = s[i];
            tmp_s %= (tmp_width + tmp_depth);

            // 縦に切る場合
            if (tmp_s <= tmp_width) {
                tmp_first = min(tmp_s, tmp_width - tmp_s);
                tmp_second = max(tmp_s, tmp_width - tmp_s);
                width.push_back(tmp_first);
                width.push_back(tmp_second);
                depth.push_back(tmp_depth);
                depth.push_back(tmp_depth);
                area.push_back(tmp_first * tmp_depth);
                area.push_back(tmp_second * tmp_depth);
            // 横に切る場合
            } else {
                tmp_s -= tmp_width;

                tmp_first = min(tmp_s, tmp_depth - tmp_s);
                tmp_second = max(tmp_s, tmp_depth - tmp_s);
                width.push_back(tmp_width);
                width.push_back(tmp_width);
                depth.push_back(tmp_first);
                depth.push_back(tmp_second);
                area.push_back(tmp_width * tmp_first);
                area.push_back(tmp_width * tmp_second);
            }
        }

        // 面積を昇順に並び替えて出力
        sort(area.begin(), area.end());

        for (int i = 0; i < area.size(); i++) {
            if (i == 0) {
                cout << area[i];
            } else {
                cout << " " << area[i];
            }
        }
        cout << endl;
    }

	return 0;
}