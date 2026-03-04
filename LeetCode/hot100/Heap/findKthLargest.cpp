#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 快速选择算法手写版
class Solution {
    // 在子数组 [left, right] 中随机选择一个基准元素 pivot
    // 根据 pivot 重新排列子数组 [left, right]
    // 重新排列后，<= pivot 的元素都在 pivot 的左侧，>= pivot 的元素都在 pivot 的右侧
    // 返回 pivot 在重新排列后的 nums 中的下标
    // 特别地，如果子数组的所有元素都等于 pivot，我们会返回子数组的中心下标，避免退化
    int partition(vector<int>& nums, int left, int right) {
        int i = left + rand() % (right - left + 1);
        int pivot = nums[i];
        swap(nums[i], nums[left]);

        i = left + 1;
        int j = right;
        while (true) {
            while (i <= j && nums[i] < pivot) {
                i++;
            }

            while (i <= j && nums[j] > pivot) {
                j--;
            }

            if (i >= j) break;

            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        // 因为 i 可能为 right + 1, 超出范围, 不能返回 i
        swap(nums[left], nums[j]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        int n = nums.size(), target_index = n - k;
        int left = 0, right = n - 1;
        while (true) {
            int i = partition(nums, left, right);
            if (i == target_index) {
                return nums[i];
            } else if (i > target_index) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }   
    }
};

int findKthLargest(vector<int>& nums, int k) {
    // 只排好你需要的那一个位置，其他的随便排
    ranges::nth_element(nums, nums.end() - k);
    return nums[nums.size() - k];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}