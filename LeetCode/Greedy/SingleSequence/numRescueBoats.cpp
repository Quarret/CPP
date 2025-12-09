#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    sort(people.begin(), people.end());
    int ans = 0;
    int i = 0, j = n - 1;
    
    while (i <= j) {
        if (i == j) {
            ans++;
            j--;
            continue;
        }

        if (people[i] + people[j] <= limit) {
            ans++;
            i++;
            j--;
        } else if (people[j] <= limit) {
            ans++;
            j--;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
