#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> removeAnagrams(vector<string>& words) {
    int n = words.size();
    vector<string> ans;

    string s= words[0];
    sort(s.begin(), s.end());
    ans.push_back(words[0]);
    
    for (int i = 1; i < n; i++) {
        string s1 = words[i];
        sort(s1.begin(), s1.end());
        if (s1 != s) {
            ans.push_back(words[i]);
            s = s1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
