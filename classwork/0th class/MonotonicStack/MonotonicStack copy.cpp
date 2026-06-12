#include "MonotonicStack.h"

int MonotonicStack::size(){
    //TODO
    return s.size();
}

void MonotonicStack::pop(){
    s.pop();
}

int MonotonicStack::top(){
    return s.top();
}

int MonotonicStack::push(int element){
    //TODO
    while (!s.empty() && s.top() > element)
    {
        s.pop();
    }
    
    s.push(element);
    return s.size();
}

int MonotonicStack::function(const int* arr,int n){
    //TODO
    // 清空栈，防止之前测试留下数据
    while (!s.empty()) pop();

    int ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // 弹出所有大于等于当前元素的数
        // 因为它们不可能成为“右边第一个更小元素”
        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        if (s.empty())
        {
            // 右边不存在更小元素
            // 价值等于自身
            ans += arr[i];
        }
        else
        {
            // 栈顶就是右边第一个更小元素
            // 价值 = 自己 - 它
            ans += arr[i] - s.top();
        }
        // 当前元素入栈
        // 供左边元素查找使用
        s.push(arr[i]);
    }
    return ans;
}

/*
可以使用这个main函数在本地进行调试，但提交时请把这段内容注释
int main() {
    MonotonicStack* ms=new MonotonicStack;
    ms->push(8);
    ms->push(4);
    ms->push(6);
    ms->push(2);
    ms->push(3);
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->top()<<endl;
    ms->pop();
    cout<<ms->size()<<endl;
    delete ms;
}
*/
