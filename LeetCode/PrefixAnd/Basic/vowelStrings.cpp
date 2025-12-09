#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    int n = words.size();
    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if ((words[i][0] == 'a' || words[i][0] == 'o' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'u') &&
        (words[i].back() == 'a' || words[i].back() == 'o' || words[i].back() == 'e' || words[i].back() == 'i' || words[i].back() == 'u')) {
            pre[i + 1] = pre[i] + 1;
        } else pre[i + 1] = pre[i];
    }

    int m = queries.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        ans.push_back(pre[queries[i][1] + 1] - pre[queries[i][0]]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
