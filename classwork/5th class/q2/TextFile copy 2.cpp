#include "TextFile.h"

// TODO: 实现 TextFile 的构造函数
TextFile::TextFile(int count, int default_val) : block_count(count) {
    // 提示：先分配指针数组，再循环分配 Data 对象
    blocks = new Data*[block_count];
    for (int i = 0; i < block_count; i++)
    {
        //每个block都是一个 指向data的指针
        blocks[i] = new Data(default_val + i);
    }
    }

// TODO: 实现 TextFile 的拷贝构造函数（深拷贝）
TextFile::TextFile(const TextFile& other) {
    block_count = other.block_count;
    blocks = new Data*[other.block_count];
    for (int i = 0; i < block_count; i++)
    {
        //每个block都是一个 指向data的指针
        blocks[i] = new Data(other.blocks[i]->seek());
    }
}

// TODO: 实现 TextFile 的析构函数
TextFile::~TextFile() {
    //进去一个一个删除
    for (int i = 0; i < block_count; i++)
    {
        delete blocks[i];
    }
    delete[] blocks;
}

// TODO: 实现 read 和 getSize
int TextFile::read(int index) const{
    if (index < block_count && index >= 0)
    {
        return blocks[index]->seek();
    }
    return -1;
    
}

int TextFile::getSize() const{
    return block_count;
}
