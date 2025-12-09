#include <bits/stdc++.h>
using ll = long long;
using namespace std;

//异或的反向操作也是异或
vector<int> decode(vector<int>& encoded, int first) {
    vector<int> ans;
    ans.push_back(first);
    
    for (auto& x: encoded) {
        ans.push_back(x ^ ans.back());
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
