#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    int l;
    int r;
    int sum;
};
vector<node> tree(100000);
vector<int> input(1000);

void build(int i, int l, int r) { 
    tree[i].l = l, tree[i].r = r;
    if (l == r) {
        tree[i].sum = input[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tree[i].sum = tree[i * 2].sum + tree[2 * i + 1].sum;
}

int search(int i, int l, int r) {
    if (tree[i].l >= l && tree[i].r <= r) {//树节点完全在l - r中
        return tree[i].sum;
    }
    if (tree[i].r < l || tree[i].l > r) {//树节点完全不在l - r中
        return 0;
    }

    ll sum = 0;
    if (tree[2 * i].r >= l) {//与左树有交集，搜左树
        sum += search(2 * i, l, r);
    }

    if (tree[2 * i + 1].l <= r) {//同理上
        sum += search(2 * i + 1, l, r);
    }

    return sum;
}

void add(int i, int dis, int k) {//单点修改
    if (tree[i].l == tree[i].r) {//为什么是l == r的时候找到单节点呢？ 是因为建树的时候“叶”结点他的两个子叶相等
        tree[i].sum += k;
        return;
    }

    if (dis <= 2 * i) {//根据单点位置选择搜索左右子树
        add(2 * i, dis, k);
    } else {
        add(2 * i + 1, dis, k);
    }

    tree[i].sum = tree[2 * i].sum + tree[2 * i + 1].sum;//递归回溯时延路径加上k

}

void modify(int p, int l, int r, int k) {//区间修改
    if (tree[p].l >= l && tree[p].r <= r && tree[p].l == tree[p].r) {//修改在l - r区间内的叶结点
        tree[p].sum += k;
        return;
    }
    
    int mid = (l + r) / 2;
    if (p <= mid) {//根据需要增加区间的mid，判断往左树走还是右树
        modify(2 * p, l, r, k);
    } else {
        modify(2 * p + 1, l, r, k);
    }

}

ll ans = 0;
void query(int p, int x) {//单点查询
    if (tree[p].l == tree[p].r && tree[p].l == x) {
        ans = tree[p].sum;
        return; 
    }

    int mid = (tree[p].l + tree[p].r) / 2;
    if (x <= mid) {
        query(2 * p, x);
    } else {
        query(2 * p + 1, x);
    }
}

void solve() {
    for (int i = 1; i <= 10; i++) {
        input[i] = i;
    }
    
    build(1, 1, 10);

    query(1, 5);

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
