#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

vector<int> ans;
stack<int> st;

void f(ListNode* node, int i) {
    if (!node) {
        ans.resize(i);
        return;
    };

    f(node->next, i + 1);
    while (!st.empty() && st.top() <= node->val) {
        st.pop();
    }
    if (!st.empty()) {
        ans[i] = st.top();
    }
    st.push(node->val);
}
vector<int> nextLargerNodes(ListNode* head) {    
   f(head, 0);
   return ans;
}


vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    stack<pair<int, int>> st; // (节点值, 节点下标)

    for (auto cur = head; cur; cur = cur->next) {
        while (!st.empty() && st.top().first < cur->val) {
            ans[st.top().second] = cur->val;
            st.pop();
        }
        
        // st为空 或 st.top()的值大于等于y
        st.emplace(cur->val, ans.size());
        ans.push_back(0); // 占位
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
