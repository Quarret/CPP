#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minAddToMakeValid(string s) {
    int n = s.size();
    vector<char> l, r;
    int cntr = 0;

    for (auto& c : s) {
        if (c == '(') l.push_back(c);
        else {
            if (l.size()) l.pop_back();
            else cntr++;
        }
    }

    return l.size() + cntr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
