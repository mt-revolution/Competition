#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    queue<pair<double, double>> point;
    // 初期条件
    point.push(make_pair(0, 0));
    point.push(make_pair(100, 0));

    pair<double, double> p, p1, p2;
    double sx, sy, tx, ty, p1x, p1y, p2x, p2y, ux, uy;
    
    for (int i = 1; i <= n; i++) {
        queue<pair<double, double>> point_new;

        // 最初の点を取り出して加えておく
        p1 = point.front();
        point.pop();
        point_new.push(p1);

        // 古い点のキューが空になるまで取り出して処理
        while (point.empty() == false) {
            // 点を取り出す
            p2 = point.front();
            point.pop();

            p1x = p1.first, p1y = p1.second;
            p2x = p2.first, p2y = p2.second;

            // 2点についてs,tの座標を求める
            sx = (2*p1x + p2x)/3, sy = (2*p1y + p2y)/3;
            tx = (p1x + 2*p2x)/3, ty = (p1y + 2*p2y)/3;

            // s,tをもとにuの座標を求める
            ux = (tx - sx)*cos(M_PI/3.0) - (ty - sy)*sin(M_PI/3.0) + sx;
            uy = (tx - sx)*sin(M_PI/3.0) + (ty - sy)*cos(M_PI/3.0) + sy;

            // 新しい点のキューに点を加える
            point_new.push(make_pair(sx, sy));
            point_new.push(make_pair(ux, uy));
            point_new.push(make_pair(tx, ty));
            point_new.push(make_pair(p2x, p2y));
            
            p1 = p2;
        }

        // 新しい点のキューに更新
        point = point_new;
    }

    while (point.empty() == false) {
        p = point.front();
        point.pop();

        cout << fixed << setprecision(10) << p.first << " " << p.second << endl;
    }
    return 0;
}