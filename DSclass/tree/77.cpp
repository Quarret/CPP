void countWordFrequency(const string& file_path, const string& output_path) {
    Trie trie;
    ifstream file(file_path);
    if (file.is_open()) {
        string word;
        while (getline(file, word, ' ')) {
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