#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int &x, int &y) {
        int cnt1 = __builtin_popcount(x), cnt2 = __builtin_popcount(y);
        if (cnt1 < cnt2) return true;
        else if (cnt1 == cnt2) {
            return x < y;
        }

        return false;
    });

    return arr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}