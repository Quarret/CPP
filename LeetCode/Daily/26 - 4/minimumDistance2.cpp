#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dis[26][26];
int init = [] {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            dis[i][j] = abs(i / 6 - j / 6) + abs(i % 6 - j % 6);
        }
    }

    return 0;
}();


class Solution {
public:
    int minimumDistance(string word) {
        int n = word.size();
        
        vector memo(n, vector(26, vector(26, -1)));
        auto dfs = [&](this auto&& dfs, int i, int finger1, int finger2) -> int {
            if (i < 0) {
                return 0;
            }

            int &res = memo[i][finger1][finger2];
            if (res != -1) return res;
            
            int end = word[i] - 'A';

            // 左手移动到 word[i];
            res = dfs(i - 1, end, finger2) + dis[finger1][end];
            
            // 右手移动到 word[i];
            res = min(res, dfs(i - 1, finger1, end) + dis[finger2][end]);

            return res;
        };

        int ans = INT_MAX;

        // 左手放在最后的字母上, 枚举右手放置位置
        for (int finger2 = 0; finger2 < 26; finger2++) {
            ans = min(ans, dfs(n - 2, word.back() - 'A', finger2));
        }
        return ans;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}