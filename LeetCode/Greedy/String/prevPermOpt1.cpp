#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> prevPermOpt1(vector<int>& arr) {    
    using pii = pair<int, int>;
    int n = arr.size();

    auto cmp = [&](pii &a, pii & b) -> bool {
        if (a.first < b.first) return true;
        else if (a.first == b.first) {
            return a.second > b.second;
        }
        return false;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    for (int i = n - 1; i >= 0; i--) {
        if (!pq.empty() && arr[i] > pq.top().first) {
            auto [num, idx] = pq.top();
            swap(arr[i], arr[pq.top().second]);
            return arr;
        }
        pq.emplace(arr[i], i);
    }

    return arr;
}

vector<int> prevPermOpt1(vector<int>& arr) {    
    int n = arr.size();
    priority_queue<int, vector<int>, greater<>> pq;
    unordered_map<int, int> mp;

    for (int i = n - 1; i >= 0; i--) {
        if (!pq.empty() && arr[i] > pq.top()) {
            int x = arr[i] - 1;
            while (x && !mp.contains(x)) {
                x--;
            }
            swap(arr[i], arr[mp[x]]);
            return arr;
        }

        if (!mp.contains(arr[i])) {
            pq.push(arr[i]);
        }
        mp[arr[i]] = i;
    }

    return arr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
