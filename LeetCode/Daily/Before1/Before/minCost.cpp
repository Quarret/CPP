#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> b1 = {4,2,2,2}, b2 = {1,4,1,2};
long long minCost(vector<int>& basket1, vector<int>& basket2) {
    sort(basket1.begin(), basket1.end());
    sort(basket2.begin(), basket2.end());
    basket1.push_back(-1);
    basket2.push_back(-1);

    int n = basket1.size(), minn = 1e9;
    int cnt1 = 0, cnt2 = 0;
    vector<int> a1, a2;
    for (int i = 0; i < n; i++) {
        if (i != 0 && basket1[i - 1] != basket1[i]) {
            int cnt = (cnt1 + 1) / 2;
            for (int j = 0; j < cnt; j++) a1.push_back(basket1[i - 1]);
            cnt1 = 0;
        }

        if (i != 0 && basket2[i - 1] != basket2[i]) {
            int cnt = (cnt2 + 1) / 2;
            for (int j = 0; j < cnt; j++) a2.push_back(basket2[i - 1]);
            cnt2 = 0;
        }
        cnt1++;
        cnt2++;
    }

    for (int x : a1) cout << x << ' ';
    cout << '\n';
    for (int y : a2) cout << y << ' ';
    cout << '\n';

    if (a1.size() != a2.size()) return -1;
    int i = 0, j = n - 1;
    long long ans = 0;
    while (i) {
        minn = min(minn, min(a1[i], a2[j]));
        ans += min(2 * minn, min(a1[i], a2[j]));
        i++;
        j--;
    }

    return ans;
}

/*
上面的史山写的依托
具体解法就是灵神的贪心:
min(2 * minn, min(a[i], b[i]))
主要是数组的去重以及那些数字重复这里我搞了好久，太菜了QAQAQ
*/

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> cnt;
    int n = basket1.size();
    for (int i = 0; i < n; i++) {
        cnt[basket1[i]]++;//若最终cnt为正则b1重复
        cnt[basket2[i]]--;//反之
    }
    
    vector<int> a, b;
    int minn = 1e9;
    for (auto [num, c] : cnt) {
        minn = min(minn, num);
        if (c % 2) return -1;
        if (c > 0) {
            for (int i = 0; i < (c + 1) / 2; i++) {
                a.push_back(num);
            }
        } else {
            for (int i = 0; i < (abs(c) + 1) / 2; i++) {
                b.push_back(num);
            }
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    long long ans = 0;
    for (int i = 0; i < a.size(); i++) ans += min(2 * minn, min(a[i], b[i]));

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    minCost(b1, b2);

    return 0;
}
