#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

template<typename T, typename Compare = less<T>>    
class LazyHeap {
    priority_queue<T, vector<T>, Compare> pq;
    unordered_map<int, int> remove_cnt; // 每个元素需要删除的次数
    size_t sz = 0;

    // 正式执行删除操作
    void apply_remove() {
        while (!pq.empty() && remove_cnt[pq.top()] > 0) {
            remove_cnt[pq.top()]--;
            pq.pop();
        }
    }

public:
    size_t size() {
        return sz;
    }

    // 删除
    void remove(T x) {
        remove_cnt[x]++;
        sz--;
    }

    // 查看堆顶
    T top() {
        apply_remove();
        return pq.top();
    }

    // 出堆
    T pop() {
        apply_remove();
        sz--;
        T x = pq.top();
        pq.pop();
        return x;
    }

    // 入堆
    void push(T x) {
        pq.push(x);
        sz++;
    }

    // 先 push 后 pop
    void push_pop(T x) {
        if (sz > 0 && Compare()(x, pq.top())) { // 无法替代堆顶
            pq.push(x);
            x = pq.top();
            pq.pop();
        }

        return x;
    }
};

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> ans(n - k + 1);
    LazyHeap<int> left;
    LazyHeap<int, greater<>> right;

    for (int r = 0; r < n; r++) {
        int in = nums[r];
        if (left.size() == right.size()) {
            right.push(in);
            left.push(right.top());
            right.pop();
        } else {
            left.push(in);
            right.push(left.top());
            left.pop();
        }

        int l = r - k + 1;
        if (l < 0) continue;
        
        if (k % 2) {
            ans[l] = left.top();
        } else {
            ans[l] = (left.top() + right.top()) / 2.0;
        }

        int out = nums[l];
        if (out <= left.top()) {
            left.remove(out);
            if (left.size() < right.size()) {
                left.push(right.pop());
            }
        } else {
            right.remove(out);
            if (left.size() > right.size() + 1) {
                right.push(left.pop());
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
