#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[10] = {1, 3, 7, 8, 5, 6, 4, 9, 2, 10};
void merge_sort(int *a, int l, int r) {
  if (r - l <= 1) return;
  // 分解
  int mid = l + ((r - l) >> 1);
  merge_sort(a, l, mid); 
  merge_sort(a, mid, r);
  // 合并
  int tmp[1024] = {};  // 请结合实际情况设置 tmp 数组的长度（与 a 相同），或使用
                       // vector；先将合并的结果放在 tmp 里，再返回到数组 a
  merge(a + l, a + mid, a + mid, a + r, tmp + l);  // pointer-style merge
  for (int i = l; i < r; ++i) a[i] = tmp[i];
}

int n = 10;//假设n为a中元素的个数
void solve() {
    merge_sort(a, 0, 10);

    if (n % 2) {//奇数情况
        cout <<a[n / 2] << '\n';
    } else {
        cout << (double)(a[n / 2 - 1] + a[n / 2]) / 2 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}    
