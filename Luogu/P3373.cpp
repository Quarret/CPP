#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q, m;
int tree[400005], lazy[400005], mul[400005], a[100005];

void build(int l, int r, int p) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    
    build(l, mid, 2 * p);
    build(mid + 1, r, 2 * p + 1);

    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

void pd(int l1, int r1, int l, int r, int )
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n >> q >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }
    
    build(1, n, 1);
    
    while (q--) {
        int k, pos, x ,y;
        cin >> pos >> x >> y;

        if (pos == 1) {
            cin >> k;
            mul(x, y, 1, n, 1, k);
        } else if (pos == 2) {
            cin >> k;
            add(x, y, 1, n, 1, k);
        } else {
            cout << getsum(x, y, 1, n, 1);
        }

    }
}
