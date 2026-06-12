#include "mylist.h"
#include <iostream>

using namespace std;

// 构造函数
MyList::MyList() : head(nullptr), list_size(0) {}

// 析构函数
MyList::~MyList() {
    //析构，但不调用clean（），我们不希望有输出
}

// 获取指定位置的节点
MyList::Node* MyList::getNodeAt(int index) const {
    //TODO
    //如果index不合法:
        //cout<<-1<<endl;
}

// 插入操作
void MyList::insert(int index, int value) {
    //TODO
    //如果index不合法:
        //cout<<-1<<endl;
}

// 删除操作
void MyList::remove(int index) {
    //TODO
    //如果index不合法:
        //cout<<-1<<endl;
}

// 获取指定位置的元素
int MyList::get(int index) const {
    //TODO
    //如果index不合法,返回-1
}

// 设置指定位置的元素
void MyList::set(int index, int value) {
    //TOOD
    //如果index不合法:
        //cout<<-1<<endl;
}

// 获取线性表的大小
int MyList::size() const {
    //TODO
    //空就返回0
}

// 清空线性表
void MyList::clear() {
    //TODO
    cout<<"Cleared"<<endl;//不要修改
}

// 查询从 index 开始的前 k 个元素的和
int MyList::sum_from(int index, int k) const {
    //TOOD
    //比如1，2，3，4，5，6 sum（0，2） 就是1+2=3
    //如果操作不合法,返回-1
}

// 反转链表
void MyList::reverse() {
    //TODO
    //注意指针的操作，我们不希望你只是交换值
}
void MyList::merge(MyList& other){
    //TODO
    
}
//可以用这个main函数本地测试！或者修改内容~
//提交时候务必注释哦~
// int main(){
//   MyList L;
//   L.insert (0, 10);
//   L.insert (1, 20);
//   L.insert (2, 30);
//   cout<<L.get(0)<<endl; 
//   cout<<L.get(1)<<endl;
//   L.set (1, 25);
//   cout<<L.get(1)<<endl;
//   cout<<L.size()<<endl;
//   L.remove (1);
//   cout<<L.get(1)<<endl;
//   cout<<L.sum_from (0, 2)<<endl;
//   L.reverse();
//   cout<<L.get(0)<<endl;
// }
