#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<int> idxs(n);
    ranges::iota(idxs, 0);
    sort(idxs.begin(), idxs.end(), [&](int &x, int &y) {
        if (growTime[x] > growTime[y]) return true;
        else if (growTime[x] == growTime[y]) {
            return plantTime[x] < plantTime[y];
        }

        return false;
    });
    
    int t = 0, ans = 0;
    for (int idx : idxs) {
        t += plantTime[idx];
        ans = max(ans, t + growTime[idx]);
    }

    return t;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
