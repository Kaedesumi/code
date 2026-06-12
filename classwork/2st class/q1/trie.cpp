#include <iostream>
#include "trie.h"
using namespace std;



TrieNode::TrieNode() {
    // TODO
    val = '\0';
    isend = false;
    prefixCnt = 0;
}
TrieNode::TrieNode(char v) {
    // TODO
    val = v;
    isend = false;
    prefixCnt = 0;
}
TrieNode::~TrieNode() {
    // TODO
    for (int i = 0; i < child.size(); i++) {
        delete child[i];
    }

    cout << "~TrieNode!" << endl;
}
Trie::Trie() {
    // TODO
    root = new TrieNode();
    wordCnt = 0;
}
Trie::~Trie() {
    // TODO
    delete root;
}
void Trie::Insert(std::string st) {
    // TODO
    // 从根节点开始插入
    TrieNode* cur = root;
    wordCnt++;

    // 依次处理字符串中的每个字符
    for (int i = 0; i < st.size(); i++) {

        // nxt 用来记录：
        // 当前字符对应的子节点是否已经存在
        TrieNode* nxt = nullptr;

        // 在当前节点的所有子节点中查找
        // 有没有字符等于 st[i] 的节点
        for (int j = 0; j < cur->child.size(); j++) {

            // 找到了对应字符
            if (cur->child[j]->val == st[i]) {

                // 保存这个节点地址
                nxt = cur->child[j];

                // 已经找到，不需要继续找
                break;
            }
        }

        // 如果没找到对应字符
        if (nxt == nullptr) {

            // 创建一个新节点
            // 节点中保存当前字符
            nxt = new TrieNode(st[i]);

            // 把新节点挂到当前节点下面
            cur->child.push_back(nxt);
        }

        // 无论是找到的旧节点
        // 还是新创建的节点
        // 都继续向下走
        cur = nxt;
        cur->prefixCnt++;
    }

    // for循环结束后
    // cur停在最后一个字符对应的节点

    // 标记：
    // 从root到这里构成一个完整单词
    cur->isend = true;
}
bool Trie::Lookup(std::string st) {
    // TODO

    // 从根节点开始查
    TrieNode* cur = root;

    // 依次检查字符串中的每个字符
    for (int i = 0; i < st.size(); i++) {

        // nxt 记录当前字符对应的子节点
        TrieNode* nxt = nullptr;

        // 在当前节点的 child 里找 st[i]
        for (int j = 0; j < cur->child.size(); j++) {

            // 找到对应字符
            if (cur->child[j]->val == st[i]) {
                nxt = cur->child[j];
                break;
            }
        }

        // 如果没找到，说明路径断了
        if (nxt == nullptr) {
            return false;
        }

        // 找到了，继续往下走
        cur = nxt;
    }

    // 字符都走完后
    // 必须检查最后节点是不是完整单词结尾
    return cur->isend;
}
int Trie::Prefix(std::string st) {
    // TODO
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
