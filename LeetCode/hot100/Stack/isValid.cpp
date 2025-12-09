#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool isValid(string s) {
    stack<int> left, right;
    unordered_map<char, char> mp;
    mp['('] = ')';
    mp['['] = ']';
    mp['{'] = '}';
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') left.push(c);
        else {
            if (left.empty() || left.top() != mp[c]) return false;
            else left.pop();
        }
    }

    if (left.size()) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
