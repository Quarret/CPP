#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// BFS模拟 每次只做一次 累加 或 轮转
string findLexSmallestString(string s, int a, int b) {
    queue<string> q;
    q.push(s);
    unordered_set<string> vis{s};
    string ans = s;
    int n = s.size();

    while (!q.empty()) {
        s = q.front();
        q.pop();

        ans = min(ans, s);

        // 累加
        string s1 = s;
        for (int i = 1; i < n; i += 2) {
            s1[i] = (s1[i] - '0' + a) % 10 + '0';
        }

        // 轮转
        string s2 = s.substr(n - b) + s.substr(0, n - b);

        for (auto &t : {s1, s2}) {
            if (!vis.contains(t)) {
                vis.insert(t);
                q.push(t);
            }
        }
    }

    return ans;
}

/*
裴蜀定理
ax + by = C 
该方程有解, 当且仅当 C = gcd(a, b) 的倍数
*/ 
string findLexSmallestString(string s, int a, int b) {
    int n = s.size();
    int step = gcd(b, n);
    int g = gcd(a, 10);
    string ans;

    // 能到在 0 位置上的数值 0 = (i + k * b) % n
    for (int i = 0; i < n; i += step) {
        string t = s.substr(i) + s.substr(0, i); // 轮转
        
        auto modify = [&](int start) -> void {
            int ch = s[start] - '0';
            
            // ch % g 为数字 ch 能够变成的最小数字
            // r = (ch + k * a) % 10
            // inc 为变成最小数字的增量
            int inc = ch % g - ch + 10;
            for (int j = start; j < n; j += 2) {
                t[j] = (t[j] - '0' + inc) % 10 + '0';
            }
        };

        // b 为偶数
        modify(0); // 累加
        if (b % 2) {
            modify(1); // 累加
        }

        if (ans.empty() || ans > t) {
            ans = move(t);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
