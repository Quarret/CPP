#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
有点像dp思路
0 1
0 1 1 ^ 10 0 ^ 10
...

由于ans[2] 与 ans[1]只有异或 (1 << i)的位置不同所以保证衔接处性质不变
然后倒序异或位相同，低位维持前面的差1位

第n个grey code
n ^ (n >> 1)
*/
vector<int> grayCode(int n) {
    vector<int> ans = {0, 1};
    
    for (int i = 1; i < n; i++) {
        for (int j = (1 << i) - 1; j >= 0; j--) {
            ans.emplace_back(ans[j] ^ (1 << i));
        }
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
