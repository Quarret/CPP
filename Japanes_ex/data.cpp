#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class word{
public:
    string pingjia;
    string pianjia;
    string luoma;
};

vector<word> data1 = {
    {"あ", "ア", "a"},
    {"い", "イ", "i"},
    {"う", "ウ", "u"},
    {"え", "エ", "e"},
    {"お", "オ", "o"},

    {"か", "カ", "ka"},
    {"き", "キ", "ki"},
    {"く", "ク", "ku"},
    {"け", "ケ", "ke"},
    {"こ", "コ", "ko"},

    {"さ", "サ", "sa"},
    {"し", "シ", "shi"},
    {"す", "ス", "su"},
    {"せ", "セ", "se"},
    {"そ", "ソ", "so"},

    {"た", "タ", "ta"},
    {"ち", "チ", "chi"},
    {"つ", "ツ", "tsu"},
    {"て", "テ", "te"},
    {"と", "ト", "to"},

    {"な", "ナ", "na"},
    {"に", "ニ", "ni"},
    {"ぬ", "ヌ", "nu"},
    {"ね", "ネ", "ne"},
    {"の", "ノ", "no"},

    {"は", "ハ", "ha"},
    {"ひ", "ヒ", "hi"},
    {"ふ", "フ", "fu"},
    {"へ", "へ", "he"},
    {"ほ", "ホ", "ho"},

    {"ま", "マ", "ma"},
    {"み", "ミ", "mi"},
    {"む", "ム", "mu"},
    {"め", "メ", "me"},
    {"も", "モ", "mo"},

    {"や", "ヤ", "ya"},
    {"い", "イ", "i"},
    {"ゆ", "ユ", "yu"},
    {"え", "エ", "e"},
    {"よ", "ヨ", "yo"},

    {"ら", "ラ", "ra"},
    {"り", "リ", "ri"},
    {"る", "ル", "ru"},
    {"れ", "レ", "re"},
    {"ろ", "ロ", "ro"},

    {"わ", "ワ", "wa"},
    {"い", "イ", "i"},
    {"う", "ウ", "u"},
    {"え", "エ", "e"},
    {"を", "ヲ", "wo"},

    {"ん", "ン", "n"}
};

int main() {
    cout << "选择联系模式:\n1. 平假名对应片假名\n2. 片假名对应平假名\n3. 罗马音对应平假名 \n4. 罗马音对应片假名\n5. 平假名对应罗马音\n6. 片假名对应罗马音\n";
    int mode;
    cout << "输入:";
    cin >> mode;

    if (mode == 1) {
        while (1) {
            int num = rand() % 51;
            cout << data1[num].pingjia << '\n';
            string tmp, tmp1;
            tmp1 = data1[num].pianjia;
            cout << "输入:";
            cin >> tmp;

            if (tmp1 == tmp) {
                cout << "恭喜答对!!!\n";
            } else {
                cout << "错误!!\n正确答案:" << data1[num].pianjia << '\n';
            }
        }
    }

    if (mode == 2) {
        while (1) {
            int num = rand() % 51;
            cout << data1[num].pianjia << '\n';
            string tmp;
            cout << "输入:";
            cin >> tmp;

            if (tmp == data1[num].pingjia) {
                cout << "恭喜答对!!!\n";
            } else {
                cout << "错误!!\n正确答案:" << data1[num].pingjia << '\n';
            }
        }
    }

    if (mode == 3) {
        while (1) {
            int num = rand() % 51;
            cout << data1[num].luoma << '\n';
            string tmp;
            cout << "输入:";
            cin >> tmp;

            if (tmp == data1[num].pingjia) {
                cout << "恭喜答对!!!\n";
            } else {
                cout << "错误!!\n正确答案:" << data1[num].pingjia << '\n';
            }
        }
    }

    if (mode == 4) {
        while (1) {
            int num = rand() % 51;
            cout << data1[num].luoma << '\n';
            string tmp;
            cout << "输入:";
            cin >> tmp;

            if (tmp == data1[num].pianjia) {
                cout << "恭喜答对!!!\n";
            } else {
                cout << "错误!!\n正确答案:" << data1[num].pianjia << '\n';
            }
        }
    }

    if (mode == 5) {
        while (1) {
            int num = rand() % 51;
            cout << data1[num].pingjia << '\n';
            string tmp;
            cout << "输入:";
            cin >> tmp;

            if (tmp == data1[num].luoma) {
                cout << "\033[032mAccepted\033[0m!!!\n";
                cout << '\n';
            } else {
                cout << "\033[031mWrong Answer!!!\033[0m!!\n\033[033m正确答案:\033[0m" << data1[num].luoma << '\n';
                cout << '\n';
            }
        }
    }

    if (mode == 6) {
        while (1) {
            int num = rand() % 51;
            cout << data1[num].pianjia << '\n';
            string tmp;
            cout << "输入:";
            cin >> tmp;

            if (tmp == data1[num].luoma) {
                cout << "\033[032mAccepted!!!\033[0m\n";
                cout << '\n';
            } else {
                cout << "\033[031mWrong Answer!!!\033[0m\n\033[033m正确答案:\033[0m" << data1[num].luoma << '\n';
                cout << '\n';
            }
        }
    }
    
    return 0;
}
