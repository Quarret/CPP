#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
要利用匹配时字符串的奇偶性来排除答案,还需从左到右遍历确保栈括号的有序性
*/
bool isValid(string s) {
    int n = s.size();
    vector<char> l;//看左括号是否与右括号匹配->最后一个左括号要与第一个右括号匹配
    unordered_map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};

    for (int i = 0; i < n; i++) {
        if (!mp.contains(s[i])) l.push_back(s[i]);
        else {
            if (l.size() && l.back() == mp[s[i]]) l.pop_back();
            else return false;
        }
    }

    return l.empty();
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
