#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size(), num = 0;
    vector<int> num1, num2, ans(n, 0);
    for (int i = 0; i < n; i++) num += code[i];

    if (k > 0) {//正想滑动窗口
        for (int i = 1; i < n; i++) num1.push_back(code[i]);
        for (int i = 0; i < k; i++) num1.push_back(code[i]);

        int m = num1.size();

        int tmp = 0;
        for (int i = 0; i < m; i++) {
            tmp += num1[i];

            if (i < k - 1) continue;
              
            ans[i - k + 1] = tmp;
            tmp -= num1[i - k + 1];
        }
    } else if (k < 0) {//反想滑动窗口
        int t = n + k;
        for (int i = 0; i < n; i++) num2.push_back(code[i]);
        for (int i = 0; i < t - 1; i++) num2.push_back(code[i]);

        int m = num2.size();
        int tmp = 0;
        
        for (int i = 0; i < m; i++) {
            tmp += num2[i];

            if (i < t - 1) continue;
              
            ans[i - t + 1] = num - tmp;
            tmp -= num2[i - t + 1];
        }
    }
    
    return ans;
}

/*
用取模操作来实现跳转头尾，不必创建数组
一开始通过k来确定右断点，然后滑窗右滑
*/
vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> ans(n, 0);
    if (k == 0) return ans;

    int r = k > 0 ? k : n - 1;
    int num = 0;
    k = abs(k);
    for (int i = r; i >= r - k + 1; i--) num += code[i];

    
    for (int i = 0; i < n; i++) {
        ans[i] = num;

        r++;
        num += code[r % n] - code[(r - k) % n];
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
