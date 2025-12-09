ADT Tries {
    数据对象：
    class TrieNode {
    public:
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word;
    int frequency;

    TrieNode() {};
    
};
    数据关系：
    unordered_map<char, TrieNode*> children;//由map的第二元素链接起来

    基本操作
    Tire() {};//构造函数
    void insert(const string& word) {};//节点插入
    void traverse(TrieNode* node, string word, vector<pair<string, int>>& word_list) {};//遍历转入vector中
    vector<pair<string, int>> getWordFrequency()//与上函数配合遍历转入vector中
    void countWordFrequency(const string& file_path, const string& output_path)//将vector中的数据输出到out.txt中
}


//不同度：相同位置上不同的字母的个数和
例如：
threat
tacitt
tar
这三个单词的不同度为10