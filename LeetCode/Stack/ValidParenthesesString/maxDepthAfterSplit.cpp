#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    int n = seq.size(), maxx = 0, d = 0;
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        if (seq[i] == '(') {
            d++;
            maxx = max(maxx, d);
        } else {
            d--;
        }
    }

    int res = (maxx + 1) / 2;
    for (int i = 0; i < n; i++) {
        if (seq[i] == '(') {
            d++;
            if (d >= res) ans[i] = 1;
        } else {
            if (d >= res) ans[i] = 1;
            d--;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
