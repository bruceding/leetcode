#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        dicts.clear(); 
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto str : dict) {
            if (dicts.find(str.length()) == dicts.end()) {
                dicts[str.length()] = std::vector<string>{str};
            } else {
                dicts[str.length()].push_back(str);
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int len = word.length();
        if (dicts.find(len) == dicts.end()) {
            return false;
        }

        for (auto str : dicts[len]) {
            int miss = 0;
            for (int i = 0; i < len; i++) {
               if (str[i] != word[i]) {
                   ++miss;
               } 
            }

            if (miss == 1) {
                return true;
            }

        }
        return false;
    }
private:
    std::unordered_map<int, std::vector<std::string>> dicts;
};
int main() {
    MagicDictionary* obj = new MagicDictionary();
    vector<string> dict{"hello", "hallo", "leetcode"};
    obj->buildDict(dict);
    
    auto ret = obj->search("hello");
    std::cout << "hello \t" << ret << std::endl; 
    ret = obj->search("hella");
    std::cout << "hella \t" << ret << std::endl; 

    string word;
    word = "hell";
    ret = obj->search(word);
    std::cout << word << "\t" << ret << std::endl; 

    word = "leetcodea";
    ret = obj->search(word);
    std::cout << word << "\t" << ret << std::endl; 

    word = "hhllo";
    ret = obj->search(word);
    std::cout << word << "\t" << ret << std::endl; 

    MagicDictionary* obj2 = new MagicDictionary();
    vector<string> dict2{"a", "b", "c", "abc"};
    obj2->buildDict(dict2);

    word = "bbc";
    ret = obj2->search(word);
    std::cout << word << "\t" << ret << std::endl; 
    return 0;
}
