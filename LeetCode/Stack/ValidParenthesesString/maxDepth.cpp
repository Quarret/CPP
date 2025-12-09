#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxDepth(string s) {
    int n = s.size();
    vector<char> st;
    
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') cnt++;
        else if (s[i] == ')') cnt--;
        ans = max(ans, cnt); 
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
