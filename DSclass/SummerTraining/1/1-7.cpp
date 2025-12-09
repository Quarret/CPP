#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    while (1) {
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (x1 == 0 && x2 == 0 && x3 == 0 && y1 == 0 && y2 == 0 && y3 == 0) return 0;
        cout << fixed << setprecision(6) << 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) << '\n';
    }
}
