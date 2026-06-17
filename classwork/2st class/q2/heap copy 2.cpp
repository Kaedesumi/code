#include "heap.h"
#include <iostream>
using namespace std;





static void SegFault() {
    /*
        输出非法访问提示
    */
    cout << "Segmentation Fault!" << endl;
}










static MM_Struct* Tail(MM_Struct* head) {
    /*
        从 head 一直走到链表末尾
        返回最后一个节点
    */
    while (head != nullptr && head->nxt != nullptr) {
        head = head->nxt;
    }
    return head;
}




static void AddUnit(MM_Struct*& head, size_t cnt){
    /*
        在链表尾部追加 cnt 个空闲单元
        用于构造堆区或扩容
    */
    MM_Struct* tail = Tail(head);
    for (size_t i = 0; i < cnt; i++) {
        MM_Struct* p = new MM_Struct();

        if (head == nullptr) {
            head = p;
        } else {
            tail->nxt = p;
        }

        tail = p;
    }
}
static bool Find(MM_Struct* head, MM_Struct* p, MM_Struct*& pre) {
    /*
        在堆链表中查找 p

        pre 记录 p 的前一个节点

        找到返回 true
        找不到返回 false
    */
    pre = nullptr;

    while (head != nullptr && head != p) {
        pre = head;
        head = head->nxt;
    }

    return head != nullptr;
}




Heap::Heap(size_t _size){
    //TODO
    /*
    按照大小创建MMSstruct链表
    并给每个阶段赋值初始化
    */
    head = nullptr;
    size = _size;
    AddUnit(head, size / 4);
}









Heap::~Heap() {
    //TODO
    while (head != nullptr) {
        MM_Struct* p = head;
        head = head->nxt;
        delete p;
    }
}







MM_Struct *Heap::Malloc(size_t size) {
    //TODO
    /*
        需要 x / 4 个连续空闲节点

        从 head 开始找第一段足够长的空闲区域

        找到后：
            第一个节点 size = x
            其他节点 size = 0
            所有节点 locked = true

        找不到：
            堆区大小翻倍
            链表尾部追加 oldSize / 4 个节点
            重新查找
    */
    size_t need = size / 4;
    while (true) {
        MM_Struct* cur = head;

        while (cur != nullptr) {
            if (cur->locked) {
                cur = cur->nxt;
                continue;
            }

            MM_Struct* start = cur;
            size_t cnt = 0;

            while (cur != nullptr && !cur->locked && cnt < need) {
                cnt++;
                cur = cur->nxt;
            }

            if (cnt == need) {
                cur = start;

                for (size_t i = 0; i < need; i++) {
                    cur->locked = true;
                    cur->val = 0;
                    cur->size = (i == 0 ? size : 0);
                    cur = cur->nxt;
                }

                return start;
            }
        }

        size_t oldSize = this->size;
        this->size *= 2;
        AddUnit(head, oldSize / 4);
    }

}













void Heap::Free(MM_Struct *p) {
    //TODO
    /*
        p 为空：
            Segmentation Fault

        p 不在堆链表中：
            Segmentation Fault

        p 已经释放：
            Segmentation Fault

        p 是分配区域中间节点：
            Error Free

        p 是分配区域开头：
            释放整段区域
            清空 locked / size / val
            把这一整段移动到链表末尾
    */
    if (p == nullptr) {
        SegFault();
        return;
    }

    MM_Struct* pre = nullptr;
    if (!Find(head, p, pre) || !p->locked) {
        SegFault();
        return;
    }


        if (p->size == 0) {
        cout << "Error Free!" << endl;
        return;
    }




    size_t cnt = p->size / 4;
    MM_Struct* last = p;
    for (size_t i = 1; i < cnt; i++) {
        last = last->nxt;
    }
    MM_Struct* after = last->nxt;
    MM_Struct* cur = p;
    for (size_t i = 0; i < cnt; i++) {
        cur->locked = false;
        cur->size = 0;
        cur->val = 0;
        cur = cur->nxt;
    }
    if (after == nullptr) {
        return;
    }
    if (pre == nullptr) {
        head = after;
    } else {
        pre->nxt = after;
    }

    Tail(head)->nxt = p;
    last->nxt = nullptr;
}












void Heap::output(MM_Struct *p) {
    /*
        p 为空：
            Segmentation Fault

        p 不在堆链表中：
            Segmentation Fault

        p 未分配：
            Segmentation Fault

        p 是分配区域中间节点：
            只输出 p->val

        p 是分配区域开头：
            输出整段区域的 val
    */
    MM_Struct* pre = nullptr;

    if (p == nullptr || !Find(head, p, pre) || !p->locked) {
        SegFault();
        return;
    }

    if (p->size == 0) {
        cout << p->val << endl;
        return;
    }

    size_t cnt = p->size / 4;

    for (size_t i = 0; i < cnt; i++) {
        cout << p->val << " ";
        p = p->nxt;
    }

    cout << endl;

}
void Heap::setval(MM_Struct *p, int x) {
    //TODO
    /*
        p 为空：
            Segmentation Fault

        p 不在堆链表中：
            Segmentation Fault

        p 未分配：
            Segmentation Fault

        合法：
            修改 p->val
    */
    MM_Struct* pre = nullptr;
    if (p == nullptr || !Find(head, p, pre) || !p->locked) {
        SegFault();
        return;
    }

    p->val = x;
}