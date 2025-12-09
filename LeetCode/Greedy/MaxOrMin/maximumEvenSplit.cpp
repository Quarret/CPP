#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<long long> maximumEvenSplit(long long finalSum) {
    if (finalSum % 2) return {};
    
    long long cnt = finalSum / 2;
    vector<long long> ans;
    for (long long i = 1; i <= cnt; i++) {
        if (i > cnt) break;
        ans.push_back(2LL * i);
        cnt -= i;
    }

    if (cnt) ans.back() += 2LL * cnt;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
