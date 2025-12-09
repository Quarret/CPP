#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> custmors = {1, 2, 3, 4}, grumpy = {1, 0, 0, 1};
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int num = 0, ans = 0, num1 = 0;
        for (int i = 0; i < n; i++) {
            if (customers[i] && !grumpy[i]) num1 += customers[i];
            if (customers[i] && grumpy[i]) num += customers[i];

            if (i < minutes - 1) continue;

            ans = max(ans, num);
            if (customers[i - minutes + 1] && grumpy[i - minutes + 1]) num -= customers[i - minutes + 1];
        }
        
        //ans = (minutes ? num1 + ans : num1);
        return ans + num1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxSatisfied(custmors, grumpy, 0);

    return 0;
}
