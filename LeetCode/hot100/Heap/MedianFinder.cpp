#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 维持 left 与 right 之间个数差不超过 1 的关系
        if (left.size() == right.size()) {
            right.push(num);
            left.push(right.top());
            right.pop();
        } else {
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if (left.size() == right.size()) return 1.0 * (left.top() + right.top()) / 2;
        return left.top();
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}