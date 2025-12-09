#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    ranges::sort(potions);
    
    vector<int> ans;
    for (int x : spells) {
        long long val = (success + x - 1) / x;
        int cnt = potions.end() - lower_bound(potions.begin(), potions.end(), val);
        ans.push_back(cnt);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
