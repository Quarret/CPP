#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long numberOfWeeks(vector<int>& milestones) {
    long long n = 0;
    for (int x : milestones) {
        n += 1LL * x;
    }   
    long long m = *max_element(milestones.begin(), milestones.end());
    
    n -= max((m - 1) - (n - m), 0LL);

    return n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
