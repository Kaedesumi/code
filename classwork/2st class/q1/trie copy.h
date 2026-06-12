#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>

struct TrieNode {
    char val;
    bool isend;
    int prefixCnt;
    std::vector<TrieNode *> child;

    TrieNode();
    TrieNode(char v);
    ~TrieNode();
};

class Trie {
private:
    TrieNode *root;
    int wordCnt;

public:
    Trie();
    ~Trie();
    void Insert(std::string st);
    bool Lookup(std::string st);
    int Prefix(std::string st);
};

#endif