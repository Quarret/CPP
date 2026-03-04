#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
枚举
一对对遍历 S = (y - x) * min(h[x], h[y])
不必回头，回头会算重

O(n ^ 2) out

对于每个左端x，逆向寻找比他大于等于的第一个右端以及第一个小于的右端，比这两个S
比完全枚举少一点情况
*/
vector<int> nums;
int maxArea(vector<int>& height) {
        int n = height.size();
        int maxx = 0, s1 = 0, s2 = 0, s3 = 0;
        for (int i = 0; i < n; i++) {
            int flag = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (height[j] >= height[i]) {
                    s1 = (j - i) * height[i];
                    flag = 1;
                } else {
                    s3 = (j - i) * height[j];
                    s2 = max(s2, s3);
                }

                if (flag) break;
            }

            maxx = max(maxx, max(s1, s2));
        }

        return maxx;
}

/*
对于这种左右边界的题目，最好从双指针的角度来思考
对于已知的左右指针l, r，左指针右移，右指针左移，移动较小的那一段
移动大段，其后的左右对值必定是小于原（l, r)的
移动小段，必定大于等于原(l, r)

是否将所有对都考虑进来?
当h[l] < h[r]时，右移l， 相当于将所有 r 左移接近 l 对都枚举完,大于同理
当h[l] == h[r]时，移动l与r的结果相同
*/
int maxArea1(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
        int area = min(height[l], height[r]) * (r - l);
        ans = max(ans, area);
        if (height[l] <= height[r]) {
            ++l;
        }
        else {
            --r;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tmp;
    while (cin >> tmp) {
        nums.push_back(tmp);
    }

    return 0;
}
