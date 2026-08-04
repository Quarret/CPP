#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Robot {
public:
    int x, y, w, h;
    int nxt[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
    int cur_dir = 0;
    Robot(int width, int height) : x(0), y(0), w(width), h(height) {

    }

    void step(int num) {
        // 周长是 2*(w-1) + 2*(h-1) = 2*(w+h-2)
        int perimeter = 2 * (w + h - 2);
        num %= perimeter;

        // 特殊情况：如果从起点开始且走了整数圈，方向变为 South
        if (num == 0 && x == 0 && y == 0 && cur_dir == 0) {
            cur_dir = 3;  // South
            return;
        }

        while (num) {
            int k = 0;
            if (cur_dir == 0) k = w - x - 1;
            else if (cur_dir == 2) k = x;
            else if (cur_dir == 1) k = h - y - 1;
            else k = y;

            if (k == 0) {
                // 在角落，转向
                cur_dir = (cur_dir + 1) % 4;
                continue;
            }

            if (num > k) {
                // 走过角落，转向继续
                x += nxt[cur_dir][0] * k;
                y += nxt[cur_dir][1] * k;
                num -= k;
                cur_dir = (cur_dir + 1) % 4;
            } else {
                // 走不完 k 步或正好走完
                x += nxt[cur_dir][0] * num;
                y += nxt[cur_dir][1] * num;
                break;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (cur_dir == 0) return "East";
        if (cur_dir == 1) return "North";
        if (cur_dir == 2) return "West";
        if (cur_dir == 3) return "South";
        return "";
    }
};


class Robot {
    int w;
    int h;
    int s = 0;

    tuple<int, int, string> getState() {
        if (s < w) {
            return {s, 0, "East"};
        } else if (s < w + h - 1) {
            return {w - 1, s - w + 1, "North"};
        } else if (s < w * 2 + h - 2) {
            return {w * 2 + h - s - 3, h - 1, "West"};
        } else {
            return {0, (w + h) * 2 - s - 4, "South"};
        }
    }

public:
    Robot(int width, int height) : w(width), h(height) {}

    void step(int num) {
        // 由于机器人只能走外圈，那么走 (w+h-2)*2 步后会回到起点
        // 把 s 取模调整到 [1, (w+h-2)*2]，这样不需要特判 s == 0 时的方向
        s = (s + num - 1) % ((w + h - 2) * 2) + 1;
    }

    vector<int> getPos() {
        auto [x, y, _] = getState();
        return {x, y};
    }

    string getDir() {
        return get<2>(getState());
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}