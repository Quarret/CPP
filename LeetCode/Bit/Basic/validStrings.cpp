/*** 
 * @Author: Quarret
 * @Date: 2025-07-07 10:18:04
 * @LastEditTime: 2025-07-07 11:12:32
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> validStrings(int n) {
    vector<string> ans;
    int num = (1 << n) - 1;

    auto check = [&](int x) -> string {
        int mask = -1, flag = 0;
        string s;
        for (int i = 0; i < n; i++) {
            flag = x % 2;
            if (flag == mask && !flag) return "";
            mask = flag;
            x /= 2;
            s += flag + '0'; 
        }

        return s;
    };


    for (int i = 1; i <= num; i++) {
        if (check(i) != "") ans.push_back(check(i));  
    }

    return ans;
}

/*
暴力搜索
利用dfs的一条路径走到头，即要么走到长度n要么无法构成符合条件串
*/
vector<string> validStrings(int n) {
    vector<string> ans;
    string path(n, '0');

    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            ans.push_back(path);//所有符合条件串都是长度n，直接覆盖即可
            return;
        }

        path[i] = '1';
        dfs(i + 1);

        if (i == 0 || path[i - 1] == '1') {
            path[i] = '0';
            dfs(i + 1);
        }
    };

    
    dfs(0);
    return ans;
}

/*
位运算
原题要求相邻位不为0
mask = ~mask转换为相邻位置不为1
若mask & (mask << 1) != 0 则相邻位置有都为1的情况
0110 -> 0011
0110 & 0011 = 0010 > 0
*/

vector<string> validStrings(int n) {
    vector<string> ans;
    int mask = (1 << n) - 1;

    for (int x = 0; x < (1 << n); x++) {
        if (((x << 1) & x) == 0) {
            ans.push_back(bitset<18>(~x).to_string().substr(18 - n));
        }

        //tmp = ~x;
        // ((tmp << 1) & x) != 0 并不能排除000这种情况
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
