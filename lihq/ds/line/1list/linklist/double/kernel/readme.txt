借助内核源码实现 ，双向有头的链表，并实现尾部插入和首部插入 及查找功能
内核源码路径/usr/src/linux-hwe-5.15-headers-5.15.0-72/include/linux

内核源码的list.h文件中有很多需要用到的函数和宏，

有部分函数和宏比如说 BUILD_BUG_ON_MSG可以通过grep "#define BUILD_BUG_ON_MSG" -R  ..

在上层目录或者本目录下找到其定义
