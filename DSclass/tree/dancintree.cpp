#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, mod = 571373;
ll tree[400005], a[100005];//要存入数据个数为n，树节点个数直接设置为4*n个
ll lazy[400005], lazy1[400005];//懒节点标记

void build(ll l, ll r, ll p) {
    if (l == r) {//叶结点赋值
        tree[p] = a[l];
        return;
    }

    //ll mid = (l + r) / 2;
    ll mid = l + (r - l) / 2;

    build(l, mid, 2 * p);//建立左树
    build(mid + 1, r, 2 * p + 1);//建立右树
    tree[p] = tree[2 * p] + tree[2 * p + 1];//由下到上求和
}

ll add(ll l1, ll r1, ll l, ll r, ll p) {
    if (l >= l1 && r <= r1) {//某节点包含在[l1, r1]
        return tree[p] % mod;
    }

    //ll mid = (l + r) / 2;
    ll mid = l + (r - l) / 2;
    ll sum = 0;

    if (lazy[p]) {
        tree[2 * p] += (mid - l + 1) * lazy[p];
        lazy[2 * p] += lazy[p];
        tree[2 * p + 1] += (r - mid) * lazy[p];
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }

    if (lazy1[p]) {
        tree[2 * p] *= lazy1[p];
        lazy1[2 * p] = lazy1[p];
        tree[2 * p + 1] *= lazy1[p];
        lazy1[2 * p + 1] = lazy1[p];
        lazy1[p] = 0;
    }

    if (l1 <= mid) {//搜素左树
        sum += add(l1, r1, l, mid, 2 * p);
    }
    if (r1 > mid) {//搜素右树
        sum += add(l1, r1, mid + 1, r, 2 * p + 1);
    }
    return sum;
}


//假设要在区间[l1, r1]上每个数增加k
void addupdate(ll l1, ll r1, ll l, ll r, ll p, ll k) {
    if (l >= l1 && r <= r1) {//某节点包含在[l1, r1]
        tree[p] += (r - l + 1) * k;
        lazy[p] += k;
        return;
    }

    //ll mid = (l + r) / 2;
    ll mid = l + (r - l) / 2;
    
    if (lazy[p]) {//懒标记的向下传递以及数值更新
        tree[2 * p] += (mid - l + 1) * lazy[p];
        lazy[2 * p] += lazy[p];
        tree[2 * p + 1] += (r - mid) * lazy[p];
        lazy[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }

    if (l1 <= mid) addupdate(l1, r1, l, mid, 2 * p, k);//搜素左树
    if (r1 > mid) addupdate(l1, r1, mid + 1, r, 2 * p + 1, k);//搜索右树

    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

void multupdate(int l1, int r1, int l, int r, int p, int k) {
    if (l1 <= l && r <= r1) {
        tree[p] *= k;
        lazy1[p] = k;
        return;
    }
    
    int mid = l + (r - l) / 2;

    if (lazy1[p]) {
        tree[2 * p] *= lazy1[p];
        lazy1[2 * p] = lazy1[p];
        tree[2 * p + 1] *= lazy1[p];
        lazy1[2 * p + 1] = lazy1[p];
        lazy1[p] = 0;
    }

    if (l1 <= mid) multupdate(l1, r1, l, mid, 2 *p , k);
    if (mid < r1) multupdate(l1, r1, mid + 1, r, 2 * p + 1, k);

    tree[p] = tree[2 * p] + tree[2 * p + 1];
}
int m;
void solve() {

    cin >> n >> m >> mod;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= mod;
    }

    build(1, n, 1);
    
    ll pos, x, y, k;
    for (ll i = 1; i <= m; i++) {
        cin >> pos >> x >> y;
        if (pos == 1) {
            cin >> k;
            multupdate(x, y, 1, n, 1, k);
        } else if (pos == 2) {
            cin >> k;
            addupdate(x, y, 1, n, 1, k);
        } else {
            cout << add(x, y, 1, n, 1) % mod << '\n';
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
