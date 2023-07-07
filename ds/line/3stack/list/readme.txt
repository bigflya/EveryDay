用到了二次封装的方法

linklist是底层的库，stack中进行相关的实现，最后用main充当主调，来进行测试。

并且在.h中进行了欺骗用户的行为typedef  LINKLIST  STACK;这样的写法更专业一些，让用户觉得是在用一个栈.
