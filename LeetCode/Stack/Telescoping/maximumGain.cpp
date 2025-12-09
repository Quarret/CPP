#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumGain(string s, int x, int y) {
    string tmp1, tmp2;

    auto f1 = [&](string st) -> int {
        int n = st.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            tmp1.push_back(st[i]);
            if (tmp1.size() > 1 && tmp1.back() == 'b' && tmp1[tmp1.size() - 2] == 'a') {
                num += x;
                tmp1.pop_back();
                tmp1.pop_back();
            }
        }

        return num;
    };

    auto f2 = [&](string st) -> int {
        int n = st.size();
        int num = 0;
        for (int i = 0; i < n; i++) {
            tmp2.push_back(st[i]);
            if (tmp2.size() > 1 && tmp2.back() == 'a' && tmp2[tmp2.size() - 2] == 'b') {
                num += y;
                tmp2.pop_back();
                tmp2.pop_back();
            }
        }

        return num;
    };

    int ans = 0;
    if (x >= y) ans = f1(s) + f2(tmp1);
    else ans = f2(s) + f1(tmp2);

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maximumGain("cdbcbbaaabab", 4, 5);

    return 0;
}
