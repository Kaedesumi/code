#pragma once

#include "File.h"
#include "Data.h"

// TODO: 补全类定义，使 TextFile 以 public 方式单继承自 File
class TextFile : public File{
    Data **blocks;
    int block_count;
public:
    TextFile(int count, int default_val);
    
    // TODO: 声明拷贝构造函数
    TextFile(const TextFile& other);
    
    // TODO: 声明析构函数
    ~TextFile();
    
    // TODO: 声明重写的 read 和 getSize 函数
    int read(int index) const;
    int getSize() const;
};
