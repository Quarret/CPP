#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string lexPalindromicPermutation(string s, string target) {
    int left[26]{}; // 记录字母个数
    for (char b : s) {
        left[b - 'a']++;
    }

    // 验证贪心是否有效
    auto valid = [&]() -> bool {
        for (int i = 0; i < 26; i++) {
            if (left[i] < 0) {
                return false;
            }
        }

        return true;
    };

    // 回文字符串中间的字符
    string mid_ch;
    for (int i = 0; i < 26; i++) {
        if (left[i] % 2 == 0) {
            continue;
        }

        if (!mid_ch.empty()) {
            return "";
        }
        mid_ch.push_back(i + 'a');
        left[i]--;
    }

    // 倒序贪心
    // 假设左半段与 t 的做半段相同
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        left[target[i] - 'a'] -= 2;
    }

    // 一开始倒序贪心就是对的
    if (valid()) {
        string right_s = target.substr(0, n / 2);
        reverse(right_s.begin(), right_s.end());
        right_s = mid_ch + right_s;
        if (right_s > target.substr(n / 2)) {
            return target.substr(0, n / 2) + right_s;
        }
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        int b = target[i] - 'a';
        left[b] += 2;

        // [0, i - 1] 无法做到全部一样
        if (!valid()) {
            continue;
        }

        // 把 target[i] 增大到 j
        for (int j = b + 1; j < 26; j++) {
            if (left[j] == 0) {
                continue;
            }

            // 找到答案 (下面整个循环只会遍历一次)
            left[j] -= 2;
            target.resize(i + 1);
            target[i] = j + 'a';

            for (int k = 0; k < 26; k++) {
                target += string(left[k] / 2, k + 'a');
            }

            // 镜像翻转, 构成回文串
            string right_s = target;
            reverse(right_s.begin(), right_s.end());
            target += mid_ch;
            target += right_s;

            return target;
        }

        // 没找到比 target[i] 大的数字
        // 接着回退
    }

    return "";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
