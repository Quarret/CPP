#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 模运算
int smallestRepunitDivByK(int k) {
    unordered_set<int> st;
    int x = 1 % k;
    while (x && st.insert(x).second) {
        x = (10 * x + 1) % k;
    }
    
    return x ? -1 : st.size() + 1;
}

// 鸽巢原理: k 次运算如果还没有算出答案, 则一定有重复数字
int smallestRepunitDivByK(int k) {
    int x = 1 % k;
    for (int i = 1; i <= k; i++) {
        if (x == 0) {
            return i;
        }
        x = (10 * x + 1) % k;
    }

    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
