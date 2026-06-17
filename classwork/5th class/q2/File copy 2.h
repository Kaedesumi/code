#pragma once

class File {
public:
    virtual ~File() = default;
    
    // TODO: 声明纯虚函数 read(接收一个 int 类型的 index，返回 int)
    virtual int read(int index) const = 0;
    // TODO: 声明纯虚函数 getSize(无参，返回 int)
    virtual int getSize() const = 0;
    // 提示：这两个函数都不应修改对象的状态
    
};
