#include <bits/stdc++.h>
#define ll long long

using namespace std;
void solve() {
	string s, s1, s2, s3;
	cin >> s1;
    //cout << s1 << '\n';

    if (s1.back() >= '0' && s1.back() <= '9') {
       for (int i = s1.size() - 1; i >= 0; i--) {
        if (s1[i] >= '0' && s1[i] <= '9'){
        s3 = s1[i] + s3;
        } else {
            break;
        }
       }
    }
    //cout << s3 << '\n';

    int n = s1.size();
    for (int i = 0; i < n - s3.size() - 1; i++) {
        if (s1[i] >= '0' && s1[i] <= '9') {
           int j = i + 1;
           s = s + s1[i];
           while(s1[j] >= '0' && s1[j] <= '9') {
            s = s + s1[j];
            j++;
           }
           s = s + '.';
           i = j - 1;
        } else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/') {
            s2 = s2 + s1[i];
            if(s1[i + 1] != '(') {
                s = s + s2;
                s2.clear();
            }
        } else if (s1[i] == '(') {
            int cnt = 1;
            i++;
            while(cnt) {
                if (s1[i] == '(') {
                   cnt++;
                } else if (s1[i] == ')') {
                    cnt--;
                    s = s + s2;
                    s2.clear();
                } else if (s1[i] >= '0' && s1[i] <= '9') {
                    int j = i;
                    while(s1[j] >= '0' && s1[j] <= '9') {
                         s = s + s1[j];
                         j++;
                    }
                    s = s + '.';
                } else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/') {
                    s2 = s1[i] + s2;
                }
                i++;
            }
            i--;
        }
    }
    if (s1.back() >= '0' && s1.back() <= '9') {
       s = s + s3 + '.';
       s = s + s1[n - s3.size() - 1];
    }
    cout << s << '\n';

	/*stack<int> st;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '+') {
           int num1 = st.top(); st.pop();
           int num2 = st.top(); st.pop();
           st.push(num1 + num2);
		} else if(s[i] == '-') {
		   int num1 = st.top(); st.pop();
           int num2 = st.top(); st.pop();
           st.push(num2 - num1);
		} else if(s[i] == '*') {
		   int num1 = st.top(); st.pop();
           int num2 = st.top(); st.pop();
           st.push(num2 * num1);
		} else if(s[i] == '/') {
		   int num1 = st.top(); st.pop();
           int num2 = st.top(); st.pop();
           st.push(num2 / num1);	
		} else if(s[i] >= '0' && s[i] <= '9') {
			int num = s[i] - '0', j = i;
			while(s[++j] != '.') {
				num = num * 10 + s[j] - '0';
			}
			i = j;
			st.push(num);
			//cout << num << '\n';
		} else if(s[i] == '@') break;
	}
	cout << st.top() << '\n';*/
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie();
    
    solve();
}