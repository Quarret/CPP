#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int splitNum(int num) {
    int cnt[10]{};
    while (num) {
        cnt[num % 10]++;
        num /= 10;
    }

    string new1 = "", new2 = "";
    for (int i = 0; i <= 9; i++) {
        // cnt1 < cnt2
        int cnt1 = cnt[i] / 2, cnt2 = cnt[i] - cnt1;
        if (new1.size() <= new2.size()) {
            new1 += string(cnt2, i + '0');
            new2 += string(cnt1, i + '0');
        } else {
            new1 += string(cnt1, i + '0');
            new2 += string(cnt2, i + '0');
        }
    }

    // cout << new1 << ' ' << new2 << '\n';
    return stoi(new1) + stoi(new2);    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
