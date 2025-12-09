#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class NumberContainers {
    unordered_map<int, int> idx_to_number;
    unordered_map<int, set<int>> number_to_idxs;
    
    public:    
        void change(int index, int number) {
          auto it = idx_to_number.find(index);
          if (it != idx_to_number.end()) {
            number_to_idxs[it -> second].erase(index);
          }

          idx_to_number[index] = number;
          number_to_idxs[number].insert(index);
        }
        
        int find(int number) {
            auto it = number_to_idxs.find(number);
            return it == number_to_idxs.end() || it -> second.empty() ? -1 : *((it -> second).begin());
        }
};

//懒删除
class NumberContainers {
    unordered_map<int, int> idx_to_number;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> number_to_idxs;
    
    public:
        NumberContainers() {
            
        }
    
        void change(int index, int number) {
            idx_to_number[index] = number;
            number_to_idxs[number].push(index);
        }
        
        int find(int number) {
            if (number_to_idxs.find(number) == number_to_idxs.end()) return -1;
            auto &idxs = number_to_idxs[number];
            while (!idxs.empty() && idx_to_number[idxs.top()] != number) {
                idxs.pop();
            }

            return idxs.empty() ? -1 : idxs.top();
        }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
