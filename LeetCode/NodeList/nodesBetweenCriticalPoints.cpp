#include <bits/stdc++.h>
#include "ListNode.h"
using ll = long long;
using namespace std;

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    int first = -1, before = -1e9, mindis = 1e9, maxdis = -1;
    
    vector<int> nums;
    while (head) {
        nums.push_back(head -> val);
        head = head -> next;
    }
    
    int n = nums.size();
    for (int i = 1; i < n - 1; i++) {
        if ((nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
             || (nums[i] < nums[i - 1] && nums[i] < nums[i + 1])) {
            mindis = min(mindis, i - before);
            before = i;
            first = first == -1 ? i : first; 
        }
    }

    if (first == -1 || first == before) return {-1, -1};
    return {mindis, before - first};
}

vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    if (!head || !head -> next || !head -> next -> next) {
        return {-1, -1};
    }
    
    ListNode* a = head;
    ListNode* b = head -> next;
    ListNode* c = head -> next-> next;
    int first = 0, minidx = 1e9;
    int i = 1, pre = 0;

    while (c) {
        if ((a -> val < b -> val && c -> val < b -> val) || 
                (a -> val > b -> val && c -> val > b -> val)) {
            if (pre > 0) minidx = min(minidx, i - pre);
            pre = i;
            first = first == 0 ? i : first;
        }
        
        i++;
        a = b;
        b = c;
        c = c -> next;
    }

    if (first == pre) return {-1, -1};
    return {minidx, pre - first};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
