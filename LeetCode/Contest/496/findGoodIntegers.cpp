#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<int> findGoodIntegers(int n) {
    int idx = ranges::upper_bound(ans, n) - ans.begin();
    vector<int> res;
    for (int i = 0; i < idx; i++) {
        res.push_back(ans[i]);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}