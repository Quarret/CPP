#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll n, ans, num1;
struct node {
    int num = 0;
    node* l = NULL;
    node* r = NULL;
    node() {
        num = 0;
        l = NULL;
        r = NULL;
    }
    node(node* x, node* y) {
        num = x->num + y->num;
        l = x;
        r = y;
    }

    node(node& x) {
        num = x.num;
        l = x.l;
        r = x.r;
    }

    bool operator<(node x) {
        return num < x.num;
    }
};
struct cmp{
bool operator()(node* x, node* y) {
    return x->num > y->num;
}
};

/*node* buildhuff(vector<node*>& forest) {

    node * temp1, * temp2, * temp3 = NULL;

    while (forest.size() > 1) {
        temp1 = forest.back();
        forest.pop_back();
        temp2 = forest.back();
        forest.pop_back();
        temp3 = new node(temp1, temp2);
        forest.push_back(temp3);
        sort(forest.begin(), forest.end(), cmp);
    }

    return temp3;
}*/

node* buildhuff(priority_queue<node*, vector<node*>, cmp > forest) {

    node* temp1, * temp2, * temp3 = NULL;

    while (forest.size() > 1) {
        temp1 = forest.top();
        forest.pop();
        temp2 = forest.top();
        forest.pop();
        temp3 = new node(temp1, temp2);
        forest.push(temp3);
        //sort(forest.begin(), forest.end(), cmp);
    }

    return temp3;
}

void sum(node* root, int d) {
    if (root->l == NULL && root->r == NULL) {
        ans += root->num * d;
        return;
    }

    sum(root->l, d + 1);
    sum(root->r, d + 1);
}
void solve() {
    ans = 0;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        //cout << a[i] << ' ' << '\n';
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i];
    }
    
    if (a[1] == a[n]) {
    ll num = n - 1, num1, num2;
    for (int i = 0; i <= 100; i++) {
        if (num <= (1 << (i + 1)) - 1) {
            num1 = (1 << (i + 1)) - 1 - num;//插大数据
            num2 = i;//小度
            break;
        }
    }

    ll ans1 = num2 * (b[n] - b[n - num1]) + (num2 + 1) * b[n - num1];
    cout << ans1 << '\n';
    return;
    }

    node tmp;
    node* tmp1 = NULL;
    //vector<node*> forest;
    priority_queue<node*, vector<node*>, cmp > forest;    
    for (int i = 1; i <= n; i++) {
    tmp.num = a[i];
    tmp1 = new node(tmp);
    //forest.push_back(tmp1);
    forest.push(tmp1);
    }

    //sort(forest.begin(), forest.end(), cmp);

    node* root = buildhuff(forest);

    sum(root, 0);

    cout << ans << '\n';
    
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    while (1) {
        cin >> n;
        //cout << n << '\n';
        if (!n) {
            return 0;
        }
        solve();
    }
}
