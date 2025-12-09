#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
记录每个bit位上的1个个数模3
由于重复数是3个3个出现的,所以在bit位上数字1的个数该数提供的一定都是3的倍数
所以余数就是那只有一个数的数提供的
=> 可以推广到每个数字重复x个 (偶数异或，奇数统计)
*/

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int cnt = 0;
        for (int x: nums) {
            if (x & (1 << i) == (1 << i)) cnt++;
        }
        ans |= (cnt % 3) << i; 
    }

    return ans;
}


/*
位运算的秘诀：模3(N)加法
异或运算其实是模2运算
由上做法可知我们最后所需答案是模3的结果
(a, b): (0, 0) -> (0, 1) - > (1, 0) -> (0, 0)

除 a = 0, b = 0, a必须保持为0 和 a = 1, b = 0时 b保持为0
其余都是 a = a ^ x, b = b ^ x

此时&(交集)，即可限定情况
a = (a ^ x) & (a | b)
b = (b ^ x) & ~a

由于位运算是并行的，可以推广到所有位上
*/
int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (int x: nums) {
        int tmp_a = a;
        a = (a ^ x) & (a | b);
        b = (b ^ x) & ~tmp_a;
    }

    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
