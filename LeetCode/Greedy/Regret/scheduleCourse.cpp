#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int scheduleCourse(vector<vector<int>>& courses) {
    ranges::sort(courses, {}, [](auto &p) {
        return p[1];
    });
    
    int n = courses.size();
    priority_queue<int> pq;
    int time = 1, ans = 0;
    for (int i = 0; i < n; i++) {
        int d = courses[i][0], last = courses[i][1];
        ans++;
        time += d;
        pq.push(d);

        if (time > last) {
            ans--;
            time -= pq.top();
            pq.pop();
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
