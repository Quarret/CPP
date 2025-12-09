#include <iostream>
#include <fstream>
#include <unordered_map>    
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word;
    int frequency;

    TrieNode() {
        is_end_of_word = false;
        frequency = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
        node->frequency++;
    }

    void traverse(TrieNode* node, string word, vector<pair<string, int>>& word_list) {
        if (node->is_end_of_word) {
            word_list.push_back({word, node->frequency});
        }
        for (auto& child : node->children) {
            traverse(child.second, word + child.first, word_list);
        }
    }

    vector<pair<string, int>> getWordFrequency() {
        vector<pair<string, int>> word_list;
        traverse(root, "", word_list);
        sort(word_list.begin(), word_list.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        return word_list;
    }
};

void countWordFrequency(const string& file_path, const string& output_path) {
    Trie trie;
    ifstream file(file_path);
    if (file.is_open()) {
        string word;
        while (file >> word) {
            string cleaned_word = "";
            for (char c : word) {
                if (isalpha(c)) {
                    cleaned_word += tolower(c);
                } else if (!cleaned_word.empty()) {
                    trie.insert(cleaned_word);
                    cleaned_word = "";
                }
            }
            if (!cleaned_word.empty()) {
                trie.insert(cleaned_word);
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << file_path << endl;
        return;
    }

    auto word_list = trie.getWordFrequency();

    ofstream output_file(output_path);
    if (output_file.is_open()) {
        int count = min(100, static_cast<int>(word_list.size()));
        for (int i = 0; i < count; ++i) {
            output_file << word_list[i].first << " " << word_list[i].second << endl;
        }
        output_file.close();
    } else {
        cerr << "Unable to open file: " << output_path << endl;
        return;
    }
}

int main() {
    countWordFrequency("in.txt", "out.txt");
    ifstream file("out.txt");
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    return 0;
}
