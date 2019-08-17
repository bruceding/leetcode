#include <iostream>
#include <vector>
#include <string>
using namespace std;
class TrieNode {
public:
    TrieNode(char d):data(d), isEnd(false){
       children.resize(26, 0); 
    }
    char data;
    bool isEnd;
    vector<TrieNode*> children;
};
class Trie {
public:
    Trie() {
        root = new TrieNode('/');
    }
    // 这里可以使用深度搜索实现
    bool insert(const std::string& word) {
       int len = word.size(); 

       int index; 
       TrieNode* p = root;
       int prefix = 0;
       for (int i = 0; i < len ; i++) {
           index = word[i] - 'a';
           if (p->children[index] == nullptr) {
                TrieNode* node = new TrieNode(word[i]);
                p->children[index] = node;
           } else {
                if (p->children[index]->isEnd == true) {
                    prefix++;
                }
           }
           p = p->children[index];
       }
       p->isEnd = true;
       if (prefix == len - 1) {
           return true;
       }
       return false;
    }
    TrieNode* root;
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        string ret;
        for (int i = 1; i <= 30; i++) {
            for (auto& word : words) {
                if (word.size() == i) {
                    bool r = trie.insert(word);
                    if (r && (i > ret.size() || (i == ret.size() && word < ret))) {
                       ret = word; 
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    words = {"w","wo","wor","worl", "world"};
    string ret;
    ret = sol.longestWord(words);
    std::cout << ret << std::endl;

    words = {"wo","hello"};
    ret = sol.longestWord(words);
    std::cout << ret << std::endl;

    words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    ret = sol.longestWord(words);
    std::cout << ret << std::endl;
    return 0;
}
