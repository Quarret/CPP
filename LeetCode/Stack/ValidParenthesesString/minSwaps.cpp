#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minSwaps(string s) {
    int n = s.size();
    vector<int> idx;

    for (int i = 0; i < n; i++) {
        if (s[i] == ']' && idx.size() && s[idx.back()] == '[') idx.pop_back();
        else idx.push_back(i);
    }

    int ans = (idx.size() / 2 + 1) / 2; 

    //for (int i = 0; i < m; i++) cout << s[idx[i]];

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string tmp = "[[][[[[][][[[[]]][][]]]]][[][[][][]][[[[]]][[]][[]][[]]]]]]]][]][]]][[]][[[[[[][[]][[[][]][[]]][";
    minSwaps(tmp);

    return 0;
}
