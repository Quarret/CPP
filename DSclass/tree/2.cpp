#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    node* l = NULL;
    node* r = NULL;
    int val;
};

int ans = 0, ansl = 0, ansr = 0;
void height(node* root, int x, int& ans) {
    if (root == NULL) {
        return;
    }

    x++;
    ans = max(ans, x);

    height(root->l, x, ans);
    height(root->r, x, ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    node root;
    root.val = 1;
    node root1, root2, root3, root4, root5, root6;
    root1.val = 2, root2.val = 3, root3.val = 4, root4.val = 5, root5.val = 6, root6.val = 7;
    root.l = &root1, root.r = &root2;
    root1.l = &root3, root1.r = &root4;
    root2.l = &root5;
    root3.r = &root6;

    height(&root, 0, ans);
    height(root.l, 0, ansl);
    height(root.r, 0, ansr);

    cout << ans << '\n';
    cout << ansl << ' ' << ansr << '\n';


}

