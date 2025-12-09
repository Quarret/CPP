#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class ExamTracker {
public:
    vector<pair<int, long long>> time_table;
    ExamTracker() {
        time_table.emplace_back(0, 0);
    }
    
    void record(int time, int score) {
        time_table.emplace_back(time, time_table.back().second + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        auto check = [&](int x) -> int {
            int l = -1, r = time_table.size();
            while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                if (time_table[mid].first >= x) r = mid;
                else l = mid; 
            }

            return r;
        };

        int l = check(startTime - 1), r = check(endTime);
        if (time_table[l].first != startTime - 1) l--;
        if (time_table[r].first != endTime) r--;
        return time_table[r].second - time_table[l].second;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
