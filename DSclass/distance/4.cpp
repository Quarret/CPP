#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    double x;
    double y;
} p0;

bool cmp(node x, node y) {
    return atan2(x.y - p0.y, x.x - p0.x) < atan2(y.y - p0.y, y.x - p0.x);
}

bool cmp1(node x, node y) {
    if (x.x < y.x) return 1;
    else if (x.x == y.x) {
        return x.y < y.y;
    } else return 0;
}

double cross(node p1, node p2, node p3) {
    return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

void solve() {
    int n, minny = 1e9, minnx = 1e9;
    cin >> n;
    vector<node> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;

        if (a[i].y < minny) {
            p0 = a[i];
            minny = a[i].y;
            minnx = a[i].x;
        } else if (a[i].y == minny) {
               if (a[i].x < minnx) {
                p0 = a[i];
                minnx = a[i].x;
               }    
        }
    }
    sort(a.begin(), a.end(), cmp);

    if (n < 3) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].x << ' ' << a[i].y << '\n';
        }
        return;
    }

    stack<node> s;
    s.push(a[0]);
    s.push(a[1]);
    node p1 = a[0], p2 = a[1], p3;

    for (int i = 2; i < n; i++) {
        if (cross(p1, p2, a[i]) >= 0) {
            p1 = s.top();
            s.push(a[i]);
            p2 = s.top();
        } else {
            while (1) {
                s.pop();
                s.pop();
                p2 = p1;
                p1 = s.top();
                s.push(p2);

                if (cross(p1, p2, a[i]) >= 0) {
                    p1 = p2;
                    s.push(a[i]);
                    p2 = s.top();
                    break;
                }
            }
        }
    }
    
    
    vector<node> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    sort(ans.begin(), ans.end(), cmp1);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].x << ' ' << ans[i].y << '\n';
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
