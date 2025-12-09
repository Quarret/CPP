#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int halfQuestions(vector<int>& questions) {
    unordered_map<int, int> cnt;
    for (int x : questions) {
        cnt[x]++;
    }

    vector<int> a;
    for (auto [_, c] : cnt) {
        a.push_back(c);
    }
    sort(a.begin(), a.end(), greater());

    int n = questions.size() / 2, m = a.size();
    int ans = 0, i = 0;
    while (i < m && n > 0) {
        n -= a[i++];
        ans++;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
