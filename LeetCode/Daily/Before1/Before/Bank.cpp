#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

class Bank {
    int N;
    vector<long long> Balance = {0};
public:
    Bank(vector<long long>& balance) {
        int n = balance.size();
        N = n;
        for (int i = 0; i < n; i++) {
            Balance.push_back(balance[i]);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 <= 0 || account1 > N) return false;
        if (account2 <= 0 || account2 > N) return false;
        if (Balance[account1] < money) return false;

        Balance[account1] -= money;
        Balance[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account <= 0 || account > N) return false;
        Balance[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account <= 0 || account > N || Balance[account] < money) return false;
        Balance[account] -= money;
        return true;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
