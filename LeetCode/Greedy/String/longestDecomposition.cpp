#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 迭代
int longestDecomposition(string text) {
    string pre = "", suf = "";
    int i = 0, j = text.size() - 1;

    int ans = 0;
    while (i < j) {
        pre.push_back(text[i]);
        suf.insert(0, 1, text[j]);
        
        if (pre == suf) {
            ans += 2;
            pre.clear();
            suf.clear();
        }

        i++;
        j--;
    }

    ans += !pre.empty() || i == j ? 1 : 0;
    return ans;
}

// 本题也是原问题子问题类型, 也可以递归来做
int longestDecomposition(string text) {
    if (text.empty()) {
        return 0;
    }

    // 枚举字符串长度
    for (int i = 1, n = text.size(); i <= n / 2; i++) {
        if (text.substr(0, i) == text.substr(n - i)) {
            return 2 + longestDecomposition(text.substr(i, n - 2 * i));
        }
    }

    // 字符串无法分割
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
