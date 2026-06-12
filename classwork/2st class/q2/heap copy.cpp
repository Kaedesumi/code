#include "heap.h"
#include <iostream>

using namespace std;

Heap::Heap(size_t _size) {
    size = _size;
    head = nullptr;

    size_t cnt = size / 4;
    MM_Struct* tail = nullptr;

    for (size_t i = 0; i < cnt; i++) {
        MM_Struct* node = new MM_Struct();

        if (head == nullptr) {
            head = node;
        } else {
            tail->nxt = node;
        }

        tail = node;
    }
}

Heap::~Heap() {
    MM_Struct* cur = head;

    while (cur != nullptr) {
        MM_Struct* nxt = cur->nxt;
        delete cur;
        cur = nxt;
    }

    head = nullptr;
}

MM_Struct* Heap::Malloc(size_t needSize) {
    size_t needCnt = needSize / 4;

    while (true) {
        MM_Struct* cur = head;

        while (cur != nullptr) {
            MM_Struct* start = cur;
            size_t cnt = 0;

            while (cur != nullptr && cur->locked == false && cnt < needCnt) {
                cnt++;
                cur = cur->nxt;
            }

            if (cnt == needCnt) {
                MM_Struct* p = start;

                for (size_t i = 0; i < needCnt; i++) {
                    p->locked = true;
                    p->val = 0;
                    p->size = 0;
                    p = p->nxt;
                }

                start->size = needSize;
                return start;
            }

            if (cur != nullptr) {
                cur = cur->nxt;
            }
        }

        size_t addCnt = this->size / 4;

        MM_Struct* tail = head;
        while (tail->nxt != nullptr) {
            tail = tail->nxt;
        }

        for (size_t i = 0; i < addCnt; i++) {
            tail->nxt = new MM_Struct();
            tail = tail->nxt;
        }

        this->size *= 2;
    }
}

void Heap::Free(MM_Struct* p) {
    if (p == nullptr) {
        cout << "Segmentation Fault!" << endl;
        return;
    }

    MM_Struct* pre = nullptr;
    MM_Struct* cur = head;

    while (cur != nullptr && cur != p) {
        pre = cur;
        cur = cur->nxt;
    }

    if (cur == nullptr || p->locked == false) {
        cout << "Segmentation Fault!" << endl;
        return;
    }

    if (p->size == 0) {
        cout << "Error Free!" << endl;
        return;
    }

    size_t freeCnt = p->size / 4;

    MM_Struct* end = p;
    for (size_t i = 1; i < freeCnt; i++) {
        end = end->nxt;
    }

    MM_Struct* after = end->nxt;

    if (pre == nullptr) {
        head = after;
    } else {
        pre->nxt = after;
    }

    MM_Struct* node = p;
    for (size_t i = 0; i < freeCnt; i++) {
        node->locked = false;
        node->val = 0;
        node->size = 0;
        node = node->nxt;
    }

    end->nxt = nullptr;

    if (head == nullptr) {
        head = p;
    } else {
        MM_Struct* tail = head;

        while (tail->nxt != nullptr) {
            tail = tail->nxt;
        }

        tail->nxt = p;
    }
}

void Heap::output(MM_Struct* p) {
    if (p == nullptr) {
        cout << "Segmentation Fault!" << endl;
        return;
    }

    MM_Struct* cur = head;
    while (cur != nullptr && cur != p) {
        cur = cur->nxt;
    }

    if (cur == nullptr || p->locked == false) {
        cout << "Segmentation Fault!" << endl;
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

void Heap::setval(MM_Struct* p, int x) {
    if (p == nullptr) {
        cout << "Segmentation Fault!" << endl;
        return;
    }

    MM_Struct* cur = head;
    while (cur != nullptr && cur != p) {
        cur = cur->nxt;
    }

    if (cur == nullptr || p->locked == false) {
        cout << "Segmentation Fault!" << endl;
        return;
    }

    p->val = x;
}