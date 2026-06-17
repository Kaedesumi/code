#include <iostream>
#include "trie.h"

using namespace std;

TrieNode* findChild(TrieNode* node, char c) {
    /*
        算法流程：

            遍历 node 的 child

            找到 val == c 的子节点：
                返回该子节点

            全部找完都没有：
                返回 nullptr
    */

    for (int i = 0; i < node->child.size(); i++) {
        if (node->child[i]->val == c) {
            return node->child[i];
        }
    }

    return nullptr;
}

TrieNode::TrieNode() {
    /*
        算法流程：

            初始化节点值

            标记不是单词结尾

            初始化前缀计数
    */

    val = '\0';
    isend = false;
    prefixCnt = 0;
}

TrieNode::TrieNode(char v) {
    /*
        算法流程：

            保存字符 v

            标记不是单词结尾

            初始化前缀计数
    */

    val = v;
    isend = false;
    prefixCnt = 0;
}

TrieNode::~TrieNode() {
    /*
        算法流程：

            依次 delete 所有子节点

            每个子节点会继续析构自己的子树

            输出析构提示
    */

    for (int i = 0; i < child.size(); i++) {
        delete child[i];
    }

    cout << "~TrieNode!" << endl;
}

Trie::Trie() {
    /*
        算法流程：

            创建根节点

            初始化单词总数
    */

    root = new TrieNode();
    wordCnt = 0;
}

Trie::~Trie() {
    /*
        算法流程：

            delete 根节点

            递归释放整棵字典树
    */

    delete root;
}

void Trie::Insert(string st) {
    /*
        算法流程：

            从 root 开始

            依次处理 st 的每个字符 c：

                查找当前节点下是否已有字符 c 的子节点

                如果没有：
                    创建新节点
                    放入 child

                走到该子节点

                该节点 prefixCnt++

            字符串处理结束：

                当前节点 isend = true

                wordCnt++
    */

    TrieNode* cur = root;

    for (int i = 0; i < st.size(); i++) {
        TrieNode* next = findChild(cur, st[i]);

        if (next == nullptr) {
            next = new TrieNode(st[i]);
            cur->child.push_back(next);
        }

        cur = next;
        cur->prefixCnt++;
    }

    cur->isend = true;
    wordCnt++;
}

bool Trie::Lookup(string st) {
    /*
        算法流程：

            从 root 开始

            依次处理 st 的每个字符 c：

                查找当前节点下是否有字符 c 的子节点

                如果没有：
                    返回 false

                如果有：
                    继续向下走

            字符串处理结束：

                返回当前节点是否为单词结尾
    */

    TrieNode* cur = root;

    for (int i = 0; i < st.size(); i++) {
        cur = findChild(cur, st[i]);

        if (cur == nullptr) {
            return false;
        }
    }

    return cur->isend;
}

int Trie::Prefix(string st) {
    /*
        算法流程：

            如果 st 是空串：

                空串是任何字符串的前缀

                返回 wordCnt

            从 root 开始

            依次处理 st 的每个字符 c：

                查找当前节点下是否有字符 c 的子节点

                如果没有：
                    返回 0

                如果有：
                    继续向下走

            字符串处理结束：

                返回当前节点 prefixCnt
    */

    if (st.empty()) {
        return wordCnt;
    }

    TrieNode* cur = root;

    for (int i = 0; i < st.size(); i++) {
        cur = findChild(cur, st[i]);

        if (cur == nullptr) {
            return 0;
        }
    }

    return cur->prefixCnt;
}