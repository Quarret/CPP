#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string largestMerge(string word1, string word2) {
    string ans = "";
    
    while (word1.size() || word2.size()) {
        if (word1 > word2) {
            ans += word1[0];
            word1.erase(0, 1);
        } else {
            ans += word2[0];
            word2.erase(0, 1);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
