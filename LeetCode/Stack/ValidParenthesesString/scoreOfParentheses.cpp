#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int scoreOfParentheses(string s) {
    int n = s.size(), ans = 0, depth = 0;
    int cnt[30]{};

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') depth++;
        else {
            if (s[i - 1] == '(') {
                cnt[depth]++;
            }
            else {
                cnt[depth] += 2 * cnt[depth + 1];
                cnt[depth + 1] = 0;
            }
            depth--;
        }
    }

    return cnt[1];
}

/*
另一种思路：
分数的提供只有(),我们只关注什么时候出现()与它出现的深度
*/
int scoreOfParentheses(string s) {
    int n = s.size(), ans = 0, depth = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') depth++;
        else {
            depth--;
            if (s[i - 1] == '(') ans += 1 << depth;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
