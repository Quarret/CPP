#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> ans;
    
    for (string q : queries) {
        int n = q.size();
        for (string s : dictionary) {
            int diff = 0;
            for (int i = 0; i < n; i++) {
                if (q[i] != s[i]) diff++;
            }

            if (diff <= 2) {
                ans.push_back(q);
                break;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}