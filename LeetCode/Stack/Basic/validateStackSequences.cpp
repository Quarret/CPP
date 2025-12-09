#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size(), idx = 0;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        st.push(pushed[i]);

        while (!st.empty() && st.top() == popped[idx]) {
            st.pop();
            idx++;
        }
    }

    return (idx == n ? true : false);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
