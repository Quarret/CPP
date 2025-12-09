#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> circularPermutation(int n, int start) {
    vector<int> ans, greycode(1 << n);
    int idx = 0;

    for (int i = 0; i < (1 << n); i++) {
        greycode[i] = i ^ (i >> 1);
        if (greycode[i] == start) idx = i;
    }

    int idx1 = 0;
    while (1) {
        if (ans.size() == (1 << n)) break;
        if (idx1 >= idx) ans.emplace_back(greycode[idx1 % (1 << n)]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
