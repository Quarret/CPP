#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string answerString(string word, int numFriends) {
    if (numFriends == 1) {
        return word;
    }

    int n = word.size();
    int len = n - numFriends + 1;
    char maxx = *max_element(word.begin(), word.end());
    string ans(1, 'a');

    for (int i = 0; i < n; i++) {
        if (word[i] != maxx) continue;
        string s = word.substr(i, min(len, n - i + 1));
        ans = max(ans, s);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
