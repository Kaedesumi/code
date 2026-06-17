#include <iostream>
#include "trie.h"

using namespace std;


TrieNode* findChild(TrieNode* node, char c) {
    for (int i = 0; i < node->child.size(); i++)
    {
        if (node->child[i]->val == c)
        {
            return node->child[i];
        }
    }
    return nullptr;
}





//========构造函数==========
TrieNode::TrieNode() {
    val = '0';
    isend = false;
    prefixCnt = 0;
}

TrieNode::TrieNode(char c) {
    val = c;
    isend = false;
    prefixCnt = 0;
}


TrieNode::~TrieNode(){
    for (int i = 0; i < child.size(); i++)
    {
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
    从root开始
    一次处理st的每个字符
        查找当前节点下是否已有字符c的子节点
        如果没有
            创建新节点
            放入child
        走入新节点
        该节点prefixcnt++
    字符串处理结束
        wordcnt++
        该节点isend = true;
    */
    TrieNode* cur = root;
    for (int i = 0; i < st.size(); i++)
    {
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




bool Trie::Lookup(string st){
    /*
    从root开始
    依次处理st的每个字符
        如果在节点下面没有
            结束
        如果有
            进入到节点
    结束后返回是否是单词结尾
    */
    TrieNode* cur = root;
    for (int i = 0; i < st.size(); i++)
    {
        TrieNode* next = findChild(cur, st[i]);
        if (next == nullptr)
        {
            return false;
        }
        cur = next;
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

    if (st.empty())
    {
        return wordCnt;
    }
    TrieNode *cur = root;
    for (int i = 0; i < st.size(); i++)
    {
        cur = findChild(cur, st[i]);
        if (cur == nullptr)
        {
            return 0;
        }
        
    }
    return cur->prefixCnt;
}






