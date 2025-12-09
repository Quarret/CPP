#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> findArray(vector<int>& pref) {
    vector<int> ans;
    int pre = 0;
    
    for (auto& x: pref) {
        ans.push_back(x ^ pre);
        pre = x;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
