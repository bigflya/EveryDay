> 拷贝构造函数的第一个参数为什么是引用?

若拷贝构造函数第一个参数不是引用，那么当调用拷贝构造函数的时候将会产生按值传递对象（会调用拷贝构造函数），那么这种情况下就会陷入死循环。

> 如果么有拷贝构造函数会如何？

如果调用某个类中没有拷贝构造函数，则编译器会合成构造函数，如果是内置类型则直接拷贝，如果是类类型，则会继续调用此类类型完成拷贝工作。

> 合成可靠被赋值运算符完成什么工作? 什么时候会生成合成拷贝赋值运算符？ 





> 析构函数?

析构函数与构造函数执行相反的操作，释放对象使用的资源，并销毁对象的非static成员。由于析构函数不带任何参数，所以它也不能被重载。析构函数销毁成员的顺序是逆序的，与初始化的顺序相反。**内置类型没有析构函数。**



> **隐式销毁一个内置（int char new 等）指针类型的成员不会delete它所指向的对象。**



> 如果成员变量有**指针**，要注意 有可能是**浅拷贝**。



> 如果一个类需要自定义析构函数，几乎可以肯定它也需要自定义拷贝赋值运算符和拷贝构造运算符 ，理由在13章test1.cpp中说明



> 希望阻止拷贝的类应该使用=delete ，而不是使用private



> 防范自赋值操作，可以使用两种策略，一种是判断 ，另一种是先拷贝再删除。




> 智能指针不能用new 要用make_shared




> 如何定义行为像指针一样的类？

深拷贝而已，需要为其定义拷贝构造函数和拷贝赋值运算符，来拷贝指针成员本身而不是它指向的string。**令一个类展现类似指针的行为的最好的方法就是使用shared_ptr来管理类中的资源**



> 拷贝赋值运算符重载函数和拷贝构造函数的区别？

拷贝构造函数使用传入对象的值生成一个新的对象的实例，而拷贝赋值运算符是将对象的值复制给一个已经存在的实例。**调用的是拷贝构造函数还是赋值运算符重载函数，主要是看是否有新的对象实例产生。** 如果产生了新的对象实例，那调用的是拷贝构造函数，如果没有新的对象的实例产生那调用的是拷贝赋值运算符重载函数。



>拷贝构造函数调用的主要场景：

1. 对象作为函数的参数，以传递的方式传给函数；
2. 对象作为函数的返回值，以值的方式从函数返回
3. 使用一个对象给另一个对象初始化。



> 为什么要有拷贝构造函数，他和构造函数有什么区别？

拷贝构造函数本身也是构造函数，只不过其传入的形参是自身类型的对象的引用。如果类里面没有指针成员（该指针成员指向动态申请的内存空间），是没有必要编写拷贝构造函数的。
**举个例子：** 如果有一个类CObj,它已经产生了一个对象ObjA,现在想要创建另外一个对象ObjB,如果程序中使用ObjB=ObjA,也就是说直接使用ObjA的数据给ObjB赋值。对于一般的类，这样操作没有问题，但如果CObj里面有个成员char *pStr,用来存放动态申请的字符串的地址，那么此时如果使用 ** ObjB=ObjA **那么就会出现ObjA.pStr与ObjB.pStr指向同一块内存空间，这样就会导致这块空间由谁来释放的问题，如果释放两次就会出现段错误，使用拷贝构造函数就能解决此问题，因为拷贝构造函数是new出一块新的动态内存空间ObjB.pStr 来存放ObjA.pStr中的内容。所以说这里的“拷贝”拷贝的是动态申请的空间的内容，而不是类本身的数据，对于c++内置类型 int char double 等类型会直接拷贝，而对于动态内存开辟的类型要执行拷贝构造函数。



> 拷贝构造函数的参数是自身对象类型的引用，而不是对象指针，或者值 的原因是什么?

如果不是引用 ，那么在传入参数的时候是 以pass-by-value 的方式进行值传递的，那么就是触发拷贝构造函数的调用条件，执行拷贝构造函数，因为拷贝构造函数是值传递，从而造成无穷递归的调用拷贝构造函数，直到栈溢出或者程序崩溃。



> 交换操作，自定义swap

很多时候我们希望swap的是指针而不是具体内容，因为对于32位机器指针所占内存是4个字节，而指针所指向的内容大小是未知的，swap交换指针对资源的要求更少。



> 想要在不属于类里面的成员函数中的函数中想访问到类里面的成员变量，的方法？

将此函数定义为友元函数，这样就可以访问到类里面的私有成员变量。



> 需要调用sort函数，要使用#include < algorithm >



>什么时候会调用小于号运算符重载函数？
>在C++中，小于号运算符（<）的重载函数通常在需要比较两个自定义类型的值时被调用。例如，如果你定义了一个自定义的类或结构体，并希望能够使用小于号运算符来比较该类的对象，那么你需要重载小于号运算符。

```c++
#include <iostream>

class MyClass {
public:
    int value;

    MyClass(int val) : value(val) {}

    // 重载小于号运算符
    bool operator<(const MyClass& other) const {
        return value < other.value;
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2(10);

    if (obj1 < obj2) {
        std::cout << "obj1 is less than obj2" << std::endl;
    } else {
        std::cout << "obj1 is not less than obj2" << std::endl;
    }

    return 0;
}
```

在上述示例中，定义了一个名为MyClass的类，它包含一个整数值value。然后，重载了小于号运算符，使其能够根据value的值来比较两个MyClass对象。在main()函数中，创建了两个MyClass对象，并使用小于号运算符进行比较。当obj1的value小于obj2的value时，输出为"obj1 is less than obj2"。否则，输出为"obj1 is not less than obj2"。



> 自定义swap函数没有开辟新的内存，只完成交换。

> 动态内存管理类


> 私有的成员函数是在public中调用的

> pair<string *,string *> 一种返回类型

> uninitialized_copy 接收三个迭代器参数。前两个表示输入序列，第三个表示这些元素将要拷贝到的目的空间。

> uninitialized_copy： 返回值是拷贝完成后剩余未构造的内存空间的起始位置。


> uninitialized_fill_n：把前一个函数返回值当作第一个参数，表示从这里开始，填充指定数量的值往剩余的空间中。

> alloc.construct 是一个C++中的函数，用于在堆上动态分配对象的内存空间，并调用对象的构造函数进行初始化。在使用 alloc.construct 函数时，我们需要确保已经为对象分配了足够的内存空间。

> std::allocator是C++标准库中的组件，用于管理对象的内存分配和构造。



```c++
alloc.construct(dest++, std::move(*elem++));
```

**执行以下操作：**
dest是目标位置的指针，先将其自增1，指向下一个可用的内存位置。elem是指向某对象的迭代器。通过解引用获取该对象，并使用std::move将该对象转移到目标位置。实际上这会调用拷贝或移动构造函数将该对象移动到目标位置。alloc.construct()在目标位置构造一个对象。由于目标位置已经通过拷贝或移动接收了elem指向的对象的状态，因此此时会调用该对象的拷贝或移动构造函数。




> 指针的类型和它指向的变量的类型一样吗？

指针的类型：告诉编译器该指针指向的内存地址保存了什么类型的数据，本质上程序“告诉”编译器这个数据的类型，本质上是由程序控制的，你可以选择不说，所以会看到很多 void * 指针，就是未定类型，但是内存里的数据就在那里，只不过编译器不知道它是什么变量的类型：是保存在内存中的数据的类型（含义），本质上是由数据自身决定的，是什么就是什么，只有数据类型正确，数据才能被正确解析出来
**总结：** 指针的类型类型和其所指对象没有必然联系，指针的类型相当于告诉编译器和程序员 这里面存放的是什么类型。而对象的类型由对象本身决定。



> #include <initializer_list>//一种类型

> #include <algorithm>// for_each函数

> 右值引用和左值引用的区别：左值持久，右值短暂
 ++i  是左值， i++是右值  ，函数返回值也是右值。

> 右值引用 的符号 &&

> 不能将一个左值引用绑定到一个右值表达式上，但是我们可以将一个const的左值引用或者一个右值引用绑定到表达式上
右值引用是左值
```c++
int i;
int &r2 = i*42;//错误i*42是一个右值
const int &r3 = i*42;//正确 可以将 一个const 引用绑定到 i*42是一个右值上

int &&rr2 = i*42;//正确。 i*42是一个表达式，表达式没有具体的地址，所以其是一个右值，可以推出rr2是一个右值引用
```

```c++
int &&rr1 =42;//正确， 字面值常量是右值
int &&rr2 = rr1;//错误，rr1是左值 ，因为rr1虽然是右值引用，但是其是一个变量是变量就是左值。
```

> 变量是左值，因此我们不能将一个右值引用直接绑定到一个变量上，即使这个变量是右值引用类型也不行

> 标准库move 函数

虽然不能将一个右值引用直接绑定到一个左值上面，但是可以通过标准库的move函数来将左值引用变成右值引用。
```c++
int &&rr2 = std::move(rr1);//正确，将rr1左值，通过标准库move变成右值。此时的后果是rr1将不再指向42，这个右值，而是把所有权交给了rr2， 对rr1的操作要么是销毁要么是让他指向别的右值。
```


> 不抛出异常的移动构造函数和移动赋值运算符必须标记位noexcept

> 移动赋值运算符重载函数

> 对类用移动构造函数  和拷贝构造函数都可以，但是移动构造函数的契合度更高

> 如果一个类有一个可用的拷贝构造函数而没有移动构造函数，则其对象是通过拷贝构造函数来“移动”的。拷贝赋值运算符和移动赋值运算符的情况类似。

> 三/五法则

一般来说，如果一个类定义了任何一个拷贝操作，他就应该定义所有的五个操作（拷贝构造函数、拷贝赋值运算符、析构函数、移动构造函数、移动赋值运算符）

> 移动操作的经验和建议
 
 通过在类代码中小心地使用move，可以大幅度提升性能。而如果随意在普通用户代码(与类实现代码想对)中使用移动操作，很有可能出现奇奇怪怪的问题和错误，所以一般如果不是很有把握不建议使用move操作。只有当确认此造作很安全的时刻才使用move来提升性能。

> 传递unique_ptr参数和返回unique_ptr （p417）
不能拷贝unique_ptr的规则有一个例外:我们可以拷贝或赋值一个将要被销毁的unique_ptr。

> 定义了一个移动构造函数或移动赋值运算符的类必须也定义自己的拷贝构造操作。否则，这些成员默认地被定义为删除的。


> void push_back(const X&);拷贝；传递的是一个左值引用
> void push_back(x&&);  移动；传递的是一个右值引用

以下两种做法都是错误的：
> void push_back(const X&&);右值引用执行的是移动操作；
移动操作是会销毁源的（对源做出修改），而此处加上const 意味着不能修改。与之相悖。

> void push_back(x&);  拷贝的时候我们并不希望对源进行修改，所以要加上const此处没有加，有可能误操作对传入的实参进行修改从而出现一些奇怪的问题。