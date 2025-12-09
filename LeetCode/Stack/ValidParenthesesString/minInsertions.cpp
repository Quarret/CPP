#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string tmp = "(()))(()))()())))";
int minInsertions(string s) {
    int n = s.size();
    vector<int> idx, idxl, st;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            idxl.push_back(i);
        } else {
            if (idx.size() && s[idx.back()] == ')' && i == idx.back() + 1 && idxl.size()) {
                idx.pop_back();
                idxl.pop_back();
            } else idx.push_back(i);
        }
    }

    int num1 = 0, num2 = 0, len1 = idx.size(), len2 = idxl.size();
    while (num1 <  len1 || num2 < len2) {
        if (num1 < len1 && (num2 >= len2 || idx[num1] < idxl[num2])) {
            st.push_back(idx[num1]);
            num1++;
        } else {
            st.push_back(idx[num2]);
            num2++;
        }
    }

    int m = st.size(), ans = 0, cnt = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < m; i++) {
        if (s[st[i]] == '(') {
            if (cnt1) {
                ans += 2;
                cnt1--;
            } else  cnt1++;
        }
        else {
            if (cnt2) {
                if (i - 1 >= 0 && st[i - 1] == st[i] - 1) {
                    ans++;
                    cnt2 = 0;
                } else {
                    if (cnt1 == 0) {
                        ans += 4;
                        cnt2 = 0;
                    } else if (cnt1 == 1) {
                        ans += 3;
                        cnt2 = 0;
                    } else {
                        ans += 2;
                        cnt2 = 0;
                    }
                }
            }
        }
    }

    if (cnt1) ans += 2 * cnt1;

    return ans;
}

/*
lc官方题解思路:
从左到右遍历，已每个)括号来作为是否要插入的判断点
其实和我上面写的思路相同，但就是写不出来:(

反思:我的做法想将删去后的字符串的出来，然后再进行判断，主要最后的插入判断写的太糟糕了
其实可以再遍历中对idx进行部分跳跃操作
*/
int minInsertions(string s) {
    int n = s.size();
    int lcnt = 0, res = 0, idx = 0;

    while (idx < n) {
        if (s[idx] == '(') {
            lcnt++;
            idx++;
        }
        else {
            if (lcnt) lcnt--;
            else res++;//没有左括号要插入左括号

            if (idx + 1 < n && s[idx + 1] == ')') {//有连续右括号
                idx += 2;
            } else {
                res += 1;
                idx++;
            }
        }
    }

    res += 2 * lcnt;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    minInsertions(tmp);

    return 0;
}
