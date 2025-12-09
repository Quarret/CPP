#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool makesquare(vector<int>& matchsticks) {
    int n = matchsticks.size();
    long long sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4 != 0) return false;
    int piece = sum / 4;
    vector<int> s(4);
    sort(matchsticks.begin(), matchsticks.end(), greater());
    
    auto dfs = [&](this auto&& dfs, int i) -> bool {
        if (i == n) {
            if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3]) {
                return true;
            }
            return false;
        }

        for (int j = 0; j < 4; j++) {
            if (s[j] + matchsticks[i] > piece) continue;
            s[j] += matchsticks[i];
            if (dfs(i + 1)) {
                return true;
            }
            s[j] -= matchsticks[i];  
        }

        return false;
    };

    return dfs(0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
