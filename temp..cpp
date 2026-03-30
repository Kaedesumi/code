int MonotonicStack::function(const int* arr,int n){
    int ans = 0;

    /*
    设计一个栈
    从右边开始入栈
    第一个进入后加给ans，看第二个
    如果第二个比第一个小，第二个也是孤立的直接加第二个就行
    这个时候栈就不需要第一个了，把第一个pop，把小的push，检查栈里还有没有元素，如果没有元素直接加
    */
   for (int i = n - 1; i >= 0; i--)
   {
    if (s.empty()){
    s.push(arr[i]);
    ans += arr[i];
    continue;
    }

    //如果新来的小
    while (!s.empty() && s.top() >= arr[i])
    {
        s.pop();
    }
    //如果空了
    if (s.empty())
    {
        ans += arr[i];
    }
    else{
        ans += arr[i] - s.top();
    }
    s.push(arr[i]);
    }
    return ans;
}
