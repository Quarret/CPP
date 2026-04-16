#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumIndex(vector<int>& capacity, int itemSize) {
    int n = capacity.size();
    int mn = INT_MAX, ans = -1;
    for (int i = 0; i < n; i++) {
        int x = capacity[i];
        if (x < itemSize) continue;
        if (x < mn) {
            mn = x;
            ans = i;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}