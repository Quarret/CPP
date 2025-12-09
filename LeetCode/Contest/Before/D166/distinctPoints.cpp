#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int distinctPoints(string s, int k) {
    int n = s.size();
    set<pair<int, int>> st;

    pair<int, int> p = {0, 0};
    for (int r = 0, l = 0; r < n; r++) {
        if (s[r] == 'U') p.second += 1;
        else if (s[r] == 'D') p.second -= 1;
        else if (s[r] == 'L') p.first -= 1;
        else if (s[r] == 'R') p.first += 1;

        if (r < k - 1) continue;
        st.insert(p);

        if (s[l] == 'U') p.second -= 1;
        else if (s[l] == 'D') p.second += 1;
        else if (s[l] == 'L') p.first += 1;
        else if (s[l] == 'R') p.first -= 1;
        l++;        
    }
    
    return st.size();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
