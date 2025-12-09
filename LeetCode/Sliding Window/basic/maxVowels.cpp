#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
定长滑动窗口，先记录初始窗口中的值，然后只关注入与出是否与值相关

O(n)
*/
int maxVowels(string s, int k) {
    int ans = 0, result = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        //进入窗口
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' ||  s[i] == 'u') {
            ans++;
        }

        result = max(result, ans);
        if (i < k) continue;//长度不足k + 1， Error

        if (s[i - k] == 'a' || s[i - k] == 'o' || s[i - k] == 'e' || s[i - k] == 'i' ||  s[i - k] == 'u') {
            ans--;
        }

        result = max(result, ans);
    }

    return result;
}

int maxVowels1(string s, int k) {
    int ans = 0, result = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        //进入窗口
        if (s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' ||  s[i] == 'u') {
            ans++;
        }

        //窗口不足k
        if (i < k - 1) continue;

        //离开窗口
        result = max(result, ans);
        if (s[i - k + 1] == 'a' || s[i - k + 1] == 'o' || s[i - k + 1] == 'e' || s[i - k + 1] == 'i' ||  s[i - k + 1] == 'u') {
            ans--;
        }
    }

    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;

    cout << maxVowels(s, k) << '\n';

    return 0;
}
