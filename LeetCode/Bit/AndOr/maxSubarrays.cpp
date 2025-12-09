#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
此题自己未思考出来，主要原因还是AND操作性质不熟悉
两点性质:
1. 越AND越小
2. 由第一点推出，子数组AND值不会低于数组AND值

假设数组AND值为a(a > 0)
若还从中分割出子数组，子数组AND值之和一定不小于2a,故不可分割

假设数组AND值为0
假设一个子数组AND值为0，是否还需要接着AND后续值呢？否!
接着AND值对子数组AND值无变化，且还可能降低后续子数组AND值为0
对于0 0 1这样的数据，最后一个数成一组? 错
直接把0与1并未一组,前面的子数组值一定为0
*/
int maxSubarrays(vector<int>& nums) {
    int ans = 0, a = -1;//-1 = 1111..111, -1 & any = any

    for (int x: nums) {
        a &= x;
        if (a == 0) {
            ans++;
            a = -1;
        }
    }

    return max(ans, 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
