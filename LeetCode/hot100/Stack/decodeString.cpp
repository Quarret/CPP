#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string decodeString(string s) {
    int n = s.size();

    vector<char> st;
    string ans = "", s1 = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            st.push_back(c);
        } else if (c == '[') {
            st.push_back(c);
        } else if (c == ']') {
            string s2 = s1;
            while (st.back() != '[') {
                s2 = st.back() + s2;
                st.pop_back();
            }
            st.pop_back();

            string s3 = "";
            while (!st.empty() && st.back() >= '0' && st.back() <= '9') {
                s3 = st.back() + s3;
                st.pop_back();
            }
            int k = stoi(s3);

            s1.clear();
            for (int i = 0; i < k; i++) {
                s1 += s2;
            }
            if (st.empty()) {
                ans += s1;
                s1.clear();
            }
        } else {
            if (st.empty()) ans += c;
            else st.push_back(c);
        }
    }

    return ans;
}

// 递归写法
string decodeString(string s) {
    int i = 0;

    auto decode = [&](this auto&& decode) -> string {
        string res = "";
        int k = 0;

        while (i < s.size()) {
            char c = s[i++];
            if (isalpha(c)) {
                res += c;
            } else if (isdigit(c)) {
                k = 10 * k + (c - '0');
            } else if (c == '[') { // 递
                string ret = decode();
                for (; k > 0; k--) {
                    res += ret;
                }
            } else { // 归
                break;
            }
        }

        return res;
    };

    return decode();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}