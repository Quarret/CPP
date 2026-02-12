#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int l = -1, r = n;
    if (!left.empty()) l = *ranges::max_element(left);
    if (!right.empty()) r = *ranges::min_element(right);
    // cout << l << ' ' << r << '\n';
    
    return max(n - r, l + 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}