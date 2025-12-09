#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
主题思想还是使用栈来模拟
*/
string reverseParentheses(string s) {
    vector<string> st;
    string str;
    for (auto& c : s) {
        if (c == '(') {//遇到左括号，将两左括号之间的字符串入栈，在最深层的左侧
            st.push_back(str);
            str.clear();
        } else if (c == ')') {//遇到右括号，要反转了，反转后
            reverse(str.begin(), str.end());
            str = st.back() + str;
            st.pop_back();
        } else str += c;
    }

    return str;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
