#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

int getDecimalValue(ListNode* head) {
    int ans = 0;
    
    while (head) {
        ans <<= 1;
        ans |= head -> val;
        head = head -> next;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
