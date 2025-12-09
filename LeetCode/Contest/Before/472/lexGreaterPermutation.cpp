#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


// 倒序贪心
string lexGreaterPermutation(string s, string target) {
    int left[26]{};
    int n = s.size();
    // 先假设全部相同
    for (int i = 0; i < n; i++) {
        left[s[i] - 'a']++;
        left[target[i] - 'a']--; // 消耗 s 中的一个字母 target[i]
    }

    // 从右向左尝试
    for (int i = n - 1; i >= 0; i--) {
        int b = target[i] - 'a';
        left[b]++;

        // 检查前面是否合法
        bool ok = true;
        for (int c : left) {
            if (c < 0) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            continue;
        }

        // 找到了 left 合法的情况
        for (int j = b + 1; j < 26; j++) {
            if (left[j] == 0) {
                continue;
            }

            left[j]--;
            target[i] = 'a' + j;
            target.resize(i + 1);
            for (int i = 0; i < 26; i++) {
                target += string(left[i], i + 'a');
            }

            return target;
        }

        // 增大失败, 继续遍历
    }

    return "";
}


// 按位确定答案
string lexGreaterPermutation(string s, string target) {
    int n = s.size();
    
    int cnt[26]{};
    for (char c : s) {
        cnt[c - 'a']++;
    }

    string ans = "";
    auto check = [&](int c) -> bool {
        string tmp = ans;
        tmp += c + 'a';

        // 剩下的数字从大到小填在后面, 来验证前面最小贪心是否合法
        for (int i = 25; i >= 0; i--) {
            tmp += string(cnt[i], i + 'a');
        }

        return tmp > target;
    };

    // 从左到右枚举每一位
    for (int i = 0; i < n; i++) {
        // 贪心的选择最小的
        for (int j = 0; j < 26; j++) {
            if (!cnt[j]) continue;
            cnt[j]--;
            if (check(j)) {
                ans.push_back(j + 'a');
                break;
            }
            cnt[j]++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
