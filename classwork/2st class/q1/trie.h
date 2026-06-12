#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <string>

struct TrieNode {
    char val;
    bool isend;
    std::vector<TrieNode *> child;
    // 你可以添加其他的成员变量
    
    TrieNode();
    TrieNode(char v);
    ~TrieNode();
};
class Trie {
private:
    TrieNode *root;
    // 你可以添加其他的成员变量
public:
    Trie();
    ~Trie();
    void Insert(std::string st);
    bool Lookup(std::string st);
    int Prefix(std::string st);
};

#endif