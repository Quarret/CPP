#include <bits/stdc++.h>
using ll = long long;
using namespace std;
//dfs meiju
bool judgePoint24(vector<int>& cards) {
    const double EPS = 1e-9;

    auto dfs = [&](this auto&& dfs, vector<double>& cards) {
        int n = cards.size();
        if (n == 1) return abs(cards[0] - 24) < EPS;
        
        //enumrate two cards
        for (int i = 0; i < n; i++) {
            double x = cards[i];
            for (int j = i + 1; j < n; j++) {
                double y = cards[j];

                vector<double> candidates = {x + y, x - y , y - x , x * y};//two cards results
                if (abs(x) > EPS) candidates.push_back(y / x);//gurante not 0
                if (abs(y) > EPS) candidates.push_back(x / y);

                auto new_cards = cards;
                new_cards.erase(new_cards.begin() + j);//delete one card
                for (double res : candidates) {
                    new_cards[i] = res;
                    if (dfs(new_cards)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    };

    vector<double> a(cards.begin(), cards.end());
    return dfs(a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
