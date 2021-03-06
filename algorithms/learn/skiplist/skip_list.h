#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

namespace skiplist {
static const int MAX_LEVEL = 16;    
class Node {
public:
    friend class SkipList;
    Node():data_(-1),max_level_(0) {
        init();
    }
    Node(int data, int level):data_(data),max_level_(level) {
        init();
    }
    std::string ToString() {
        std::stringstream ss;
        ss << "{\"data\":"
           << data_
           << ", \"max_level_\":"
           << max_level_
           << "}";
        return ss.str();
    }
    int data() const {
        return data_;
    }
private:
    void init() {
        for (int i = 0; i < MAX_LEVEL; i++) {
            forwards_[i] = nullptr;
        }
    }
    int data_;
    Node* forwards_[MAX_LEVEL];
    int max_level_;
};    
class SkipList {
public:
    SkipList() {
        head_ = new Node();
        level_count_ = 0;
    }
    void insert(int value) {
        int level = randomLevel();
        Node* node = new Node(value, level);

        Node* update[level];
        for (int i = 0; i < level; i++) {
            update[i] = head_;
        }
        Node* p = head_;
        for (int i = level -1; i >=0; i--) {
           while(p->forwards_[i] != nullptr && p->forwards_[i]->data_ < value) {
                 p = p->forwards_[i]; 
           } 
           update[i] = p;
        }
        for (int i = 0; i < level -1; i++) {
            node->forwards_[i] = update[i]->forwards_[i];
            update[i]->forwards_[i] = node;
        }
        if (level_count_ < level) {
            level_count_ = level;
        }
    }
    Node* find(int value) {
        Node* p = head_;

        std::cout << level_count_ << std::endl;
        for (int i = level_count_-1; i>=0; i--) {
            while(p->forwards_[i] != nullptr && p->forwards_[i]->data_ < value) {
                p = p->forwards_[i];
            }
        }

        if (p->forwards_[0] != nullptr && p->forwards_[0]->data_ == value) {
            std::cout << "here" << std::endl;
            return p->forwards_[0];
        }
        return nullptr;
    }
    void del(int value) {
        Node* p = head_;
        Node* tmp = nullptr ;
        for (int i = level_count_-1; i>=0; i--) {
           while(p->forwards_[i] != nullptr && p->forwards_[i]->data_ < value) {
                p = p->forwards_[i];
           } 

           if (p->forwards_[i] != nullptr && p->forwards_[i]->data_ == value) {
               tmp = p->forwards_[i];
               p->forwards_[i] = p->forwards_[i]->forwards_[i];
           }
        } 
        if (tmp) {
            delete tmp;
        }
    }
    void printAll() {
        Node* p = head_;
        while(p->forwards_[0] != nullptr) {
            std::cout << p->forwards_[0]->ToString() << " ";
            p = p->forwards_[0];
        }
        std::cout << std::endl;
    }
private:
    int randomLevel() {
        int level = 1;
        for (int i = 1; i < MAX_LEVEL; i++) {
            if (rand() % 2 == 1) {
                ++level;
            }
        }
        return level;
    }
    int level_count_;
    Node* head_;
};
}
#endif

