#include <iostream>
#include "trie.h"

using namespace std;

TrieNode::TrieNode() {
    val = '\0';
    isend = false;
    prefixCnt = 0;
}

TrieNode::TrieNode(char v) {
    val = v;
    isend = false;
    prefixCnt = 0;
}

TrieNode::~TrieNode() {
    for (int i = 0; i < child.size(); i++) {
        delete child[i];
    }

    cout << "~TrieNode!" << endl;
}

Trie::Trie() {
    root = new TrieNode();
    wordCnt = 0;
}

Trie::~Trie() {
    delete root;
}

void Trie::Insert(string st) {
    TrieNode* cur = root;
    wordCnt++;

    for (int i = 0; i < st.size(); i++) {
        TrieNode* nxt = nullptr;

        for (int j = 0; j < cur->child.size(); j++) {
            if (cur->child[j]->val == st[i]) {
                nxt = cur->child[j];
                break;
            }
        }

        if (nxt == nullptr) {
            nxt = new TrieNode(st[i]);
            cur->child.push_back(nxt);
        }

        cur = nxt;
        cur->prefixCnt++;
    }

    cur->isend = true;
}

bool Trie::Lookup(string st) {
    TrieNode* cur = root;

    for (int i = 0; i < st.size(); i++) {
        TrieNode* nxt = nullptr;

        for (int j = 0; j < cur->child.size(); j++) {
            if (cur->child[j]->val == st[i]) {
                nxt = cur->child[j];
                break;
            }
        }

        if (nxt == nullptr) {
            return false;
        }

        cur = nxt;
    }

    return cur->isend;
}

int Trie::Prefix(string st) {
    if (st == "") {
        return wordCnt;
    }

    TrieNode* cur = root;

    for (int i = 0; i < st.size(); i++) {
        TrieNode* nxt = nullptr;

        for (int j = 0; j < cur->child.size(); j++) {
            if (cur->child[j]->val == st[i]) {
                nxt = cur->child[j];
                break;
            }
        }

        if (nxt == nullptr) {
            return 0;
        }

        cur = nxt;
    }

    return cur->prefixCnt;
}