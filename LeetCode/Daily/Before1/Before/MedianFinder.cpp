#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

class MedianFinder {
    priority_queue<int> left;    
    priority_queue<int, vector<int>, greater<>> right;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
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
        if (left.size() == right.size() + 1) {
            return left.top();
        }

        return 1.0 * (left.top() + right.top()) / 2;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
