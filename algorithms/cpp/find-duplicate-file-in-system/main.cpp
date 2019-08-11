#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdio>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ret;

        unordered_map<string, vector<string>> maps;

        for (auto path : paths) {
            handlePath(path, maps);
        }

        for (auto iter: maps) {
            if (iter.second.size() > 1) {
                ret.push_back(iter.second);
            }
        }
        return ret;
    }
    void split(const std::string& s,
    std::vector<std::string>& sv,
                   const char delim = ' ') {
        sv.clear();
        std::istringstream iss(s);
        std::string temp;

        while (std::getline(iss, temp, delim)) {
            sv.emplace_back(std::move(temp));
        }

        return;
    }
    void handlePath(const std::string& path, unordered_map<string, vector<string>>& maps) {
        vector<string> paths;
        split(path, paths);
        if (paths.empty()) {
            return;
        }
        int len = paths.size();

        std::string rootDir = paths[0];
        //int len = paths.size();
        for (int i = 1; i < len; i++) {
            string file, content;
            bool is_content = false;
            // std::cout << paths[i] << std::endl;
            for (auto s : paths[i]) {
                if (s == '(') {
                    is_content = true;
                    continue;
                } else if (s == ')') {
                    continue;
                }
                if (is_content) {
                    content += s;
                } else {
                    file += s;
                }
            }
            std::string filePath = rootDir + "/" +file;
            // std::cout << file << "\t" << content << "\t" << filePath << std::endl;
            if (maps.find(content) == maps.end()) {
                maps[content] = std::vector<string>{filePath};
            } else {
                maps[content].push_back(filePath);
            }
        }
    }
};
void printVector(const vector<string> &vec) {
    for (auto v : vec) {
        std::cout << v << " "<< v.size()  << "\t";
    }
    std::cout << std::endl; 
}
void printVector(const vector<vector<string>> &vec) {
    for (auto v : vec) {
        printVector(v);
    }
    std::cout << std::endl; 
}
int main() {
    Solution sol;
    vector<string> paths;
    sol.split("root/a 1.txt(abcd) 2.txt(efgh) root/c 3.txt(abcd)", paths);
    printVector(paths);

    vector<string> input {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    vector<vector<std::string>> ret;
    ret = sol.findDuplicate(input);
    printVector(ret);

    input = vector<string>{"root/a 1.txt(abcd) 2.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"};
    ret = sol.findDuplicate(input);
    printVector(ret);
    return 0;
}
