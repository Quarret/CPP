/*
给你一个由 N 个正整数 A=(A 1​ ,A 2 ,…,A N) 组成的序列。高桥重复下面的操作，直到 A 包含一个或更少的正整数元素：

按降序排列 A 。然后将 A 1  和 A 2  减少 1 。
求他执行此操作的次数。

*/

#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    int sum = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        sum += A;
        max = std::max(max, A);
    }
    
    int ans = std::min(sum / 2, sum - max);
    std::cout << ans << "\n";
    
    return 0;
}