#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string largestMultipleOfThree(vector<int>& digits) {
    long long sum = reduce(digits.begin(), digits.end(), 0LL);
    int cnt[10]{};
    for (int x : digits) {
        cnt[x]++;
    }

    if (sum % 3 == 1) {
        if (cnt[1]) {
            cnt[1]--;
        } else if (cnt[4]) {
            cnt[4]--;
        } else if (cnt[7]) {
            cnt[7]--;
        } else if (cnt[2] > 1) {
            cnt[2] -= 2;
        } else if (cnt[2] && cnt[5]) {
            cnt[2]--;
            cnt[5]--;
        } else if (cnt[2] && cnt[8]) {
            cnt[2]--;
            cnt[8]--;
        } else if (cnt[5] > 1) {
            cnt[5] -= 2;
        } else if (cnt[5] && cnt[8]) {
            cnt[5]--;
            cnt[8]--;
        } else if (cnt[8] > 1) {
            cnt[8] -= 2;
        } else {
            return "";
        }
    } else if (sum % 3 == 2) {
        if (cnt[2]) {
            cnt[2]--;
        } else if (cnt[5]) {
            cnt[5]--;
        } else if (cnt[8]) {
            cnt[8]--;
        } else if (cnt[1] > 1) {
            cnt[1] -= 2;
        } else if (cnt[1] && cnt[4]) {
            cnt[1]--;
            cnt[4]--;
        } else if (cnt[1] && cnt[7]) {
            cnt[1]--;
            cnt[7]--;
        } else if (cnt[4] > 1) {
            cnt[4] -= 2;
        } else if (cnt[4] && cnt[7]) {
            cnt[4]--;
            cnt[7]--;
        } else if (cnt[7] > 1) {
            cnt[7] -= 2;
        } else {
            return "";
        }
    }

    string ans;
    for (int i = 9; i >= 0; i--) {
        ans += string(cnt[i], i + '0');
    }

    return ans[0] == '0' ? "0" : ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
