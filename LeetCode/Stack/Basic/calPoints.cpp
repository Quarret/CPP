#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int calPoints(vector<string>& operations) {
    int n = operations.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (operations[i] == "+") {
            int num1 = st.top();
            st.pop();
            int num2 = st.top() + num1;
            st.push(num1);
            st.push(num2);
        } else if (operations[i] == "D") {
            st.push(st.top() * 2);
        } else if (operations[i] == "C") {
            st.pop();
        } else st.push(stoi(operations[i]));
    }

    int ans = 0;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
