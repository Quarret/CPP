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
    bool operator<(const node& x) {
        return num < x.num;
    }
};

bool cmp(node* x, node* y) {
    return x->num > y->num;
}

node* buildhuff(vector<node*>& forest) {

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
}

void sum(node* root, int d) {
    if (root->l == NULL && root->r == NULL) {
        ans += root->num * d;
        return;
    }

    sum(root->l, d + 1);
    sum(root->r, d + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> n;
    node tmp;
    node* tmp1 = NULL;
    vector<node*> forest;
    priority_queue<node*, vector<node*>, cmp> forest;
    for (int i = 0; i < n; i++) {
        cin >> num1;
        tmp.num = num1;
        tmp1 = new node(tmp);
        forest.push_back(tmp1);
    }
    sort(forest.begin(), forest.end(), cmp);

    node* root = buildhuff(forest);

    sum(root, 0);

    cout << ans << '\n';
}
