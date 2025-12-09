#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Spreadsheet {
    public:
        unordered_map<char, vector<int>> mp;
        Spreadsheet(int rows) {
            vector<int> tmp(rows + 1, 0);
            for (int i = 0; i < 26; i++) {
                mp[(char)(i + 'A')] = tmp; 
            }
        }
        
        void setCell(string cell, int value) {
            char c = cell[0];
            int r = stoi(cell.substr(1));
            // cout << c<< ' ' << r << '\n';
            mp[c][r] = value;
        }
        
        void resetCell(string cell) {
            char c = cell[0];
            int r = stoi(cell.substr(1));
            mp[c][r] = 0;
        }
        
        int getValue(string formula) {
            int pos = formula.find('+');
            string cell1 = formula.substr(1, pos - 1);
            string cell2 = formula.substr(pos + 1);
            cout << cell1 << ' ' << cell2 << '\n';


            auto getCell = [&](string cell) -> int {
                if (cell[0] >= 'A' && cell[0] <= 'Z') {
                    char c = cell[0];
                    int r = stoi(cell.substr(1));
                    return mp[c][r];
                }
                return stoi(cell);
            };

            int v1 = getCell(cell1), v2 = getCell(cell2);
            return v1 + v2;
        }
    };


class Spreadsheet {
        public:
            unordered_map<string, int> mp;
            Spreadsheet(int rows) {
                
            }
            
            void setCell(string cell, int value) {
                mp[cell] = value;
            }
            
            void resetCell(string cell) {
                mp.erase(cell);
            }
            
            int getValue(string formula) {
                int pos = formula.find('+');
                string cell1 = formula.substr(1, pos - 1);
                string cell2 =  formula.substr(pos + 1);
                return ((isupper(cell1[0])) ? mp[cell1] : stoi(cell1)) +
                        (isupper(cell2[0]) ? mp[cell2] : stoi(cell2)); 
            }
        };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
