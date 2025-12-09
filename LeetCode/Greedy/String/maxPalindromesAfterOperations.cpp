#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxPalindromesAfterOperations(vector<string>& words) {
    int cnt[26]{};
    vector<int> a;
    for (string &w : words) {
        a.push_back(w.size());
        for (char c : w) {
            cnt[c - 'a']++;
        }
    }

    ranges::sort(a);
    int ans = 0;
    for (int x : a) {
        for (int j = 0; j < 2 * 26; j++) {
            if (j < 26) {
                if (x % 2 == 1 && cnt[j] % 2 == 1) {
                    int k = min(x, cnt[j]);
                    x -= k;
                    cnt[j] -= k;
                } else {
                    int k = min(x - x % 2, cnt[j] - cnt[j] % 2);
                    x -= k;
                    cnt[j] -= k;
                }
            } else {
                if (x % 2) x -= min(x, cnt[j % 26]);
            }

            if (x == 0) {
                ans++;
                break;
            }
        }

        if (x) break;
    }

    return ans;
}

// 位运算
int maxPalindromesAfterOperations(vector<string>& words) {
    int tot = 0, mask = 0, ans = 0;
    for (auto &w : words) {
        tot += words.size();
        for (char c : w) {
            mask ^= 1 << (c - 'a');
        }
    }
    
    // 减去奇数长度中间的单个字母
    tot -= __builtin_popcount(mask);
    ranges::sort(words, {}, [](auto &s) {
        return s.length();
    });

    for (auto &w : words) {
        tot -= words.size() / 2 * 2; // 奇数长度上面已经处理
        if (tot < 0) break;
        ans++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
