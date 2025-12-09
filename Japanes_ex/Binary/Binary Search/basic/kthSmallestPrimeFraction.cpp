#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> arr = {1,13,17,59};
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n = arr.size();
    long long lson = 1, lmom = arr.back() + 1;
    long long rson = 1, rmom = 1;
    long long midson = 0, midmom = 0;
    long long ans1 = 0, ans2 = 0;

    bool flag = 0;
    auto check = [&](long long son, long long mom) -> bool {
        long long cnt = 0, num1 = 0, num2 = 0, minn = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                if (arr[i] * mom <= arr[j] * son) {
                    cnt++;
                    if (arr[j] * son - arr[i] * mom < minn) {
                        minn = arr[j] * son - arr[i] * mom;
                        num1 = arr[i];
                        num2 = arr[j];
                    }
                }
                else break;
            }
        }

        if (cnt == k) {
            flag = 1;
            ans1 = num1;
            ans2 = num2;
        }

        return cnt >= k;
    };

    while (lson * rmom < rson * lmom) {
        midson = lson * rmom + rson * lmom;
        midmom = lmom * rmom * 2;

        int div = gcd(midson, midmom);
        if (div != 1) {
            midson /= div;
            midmom /= div;
        }

        if (check(midson, midmom)) {
            rson = midson;
            rmom = midmom;
        } else {
            lson = midson;
            lmom = midmom;
        }

        if (flag) break;
    };

    return {(int)ans1, (int)ans2}; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    kthSmallestPrimeFraction(arr, 6);

    return 0;
}
