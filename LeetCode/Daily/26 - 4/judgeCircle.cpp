#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool judgeCircle(string moves) {
    vector<int> cnt(4, 0);
    for (char c : moves) {
        if (c == 'L') cnt[0]++;
        if (c == 'R') cnt[1]++;
        if (c == 'U') cnt[2]++;
        if (c == 'D') cnt[3]++;
    }
    
    return cnt[0] == cnt[1] && cnt[2] == cnt[3];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}