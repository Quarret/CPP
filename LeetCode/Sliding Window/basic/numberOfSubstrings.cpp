#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
越长越合法滑动窗口
一旦r到达的位置合法，右移动l直至不合法

ans += l
*/
int numberOfSubstrings(string s) {
    int n = s.size(), cnta = 0, cntb = 0, cntc = 0, ans = 0, l = 0;

    for (int r = 0; r < n; r++) {
        cnta += s[r] == 'a';
        cntb += s[r] == 'b';
        cntc += s[r] == 'c';

        if (!(cnta >= 1 && cntb >= 1 && cntc >= 1)) continue;

        while (cnta >= 1 && cntb >= 1 && cntc >= 1) {
            cnta -= s[l] == 'a';
            cntb -= s[l] == 'b';
            cntc -= s[l] == 'c';
            l++;
        }

        ans += l;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
