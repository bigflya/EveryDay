这个程序实现的是一个双向环链的一个有头链表，并且节点中的  data成员采用的是一个数组，为什么采用数组呢？这里数组可以是长度为0的，用 来占一个入口地址，这里将数组长度设置为1是因为 长度为0的数组是c99之后才支持的。长度为1也就占用4个字节的长度。一个指针占的长度也是4个字节（默认32位机器）




对此代码进行封装，封装成静态库和动态库

动态库==共享库

会放在特定的

动态库占运行时间

静态库占编译时间



对此代码进行封装，封装成静态库和动态库

动态库==共享库

会放在特定的

动态库占运行时间

静态库占编译时间





## 一、静态库

libxx.a

xx指代库名

生成静态库$:   ar -cr  libxx.a  yyy.o 

yyy.o  指所依赖的文件



发布到

/usr/local/include

/usr/local/lib



cp linklist.h /usr/local/include/

cp liblinklist.a /usr/local/lib/



gcc -L/usr/local/lib -o main main.c -lxx

-l 指链接选项 ，此参数必须放在最后



ldd ./main  打印 main 所依赖的动态库



gcc -o main main.c -llinklist

表示编译生成main   依赖main.c   和静态库 linklist   

## 二、动态库

libxx.so



gcc -shared -fPIC -o libxx.so yyy.c



发布到

/usr/local/include

/usr/local/lib

在/etc/ld.so.conf 中添加路径

运行/sbin/ldconfig     重读 /etc/ld.so.conf

gcc -I/usr/local/include -L/usr/local/lib -o ... -lxx

-I 指定include 目录 ，-L指定库目录，因为这里已经在ld.se.conf中添加了路径而且，是将库发布到标准的库目录文件夹，所以可以省略-I 和-L

直接执行gcc -o main main.c -llinklist



非root用户发布

cp xx.so  ~/lib

export LD_LIBRARY_PATH=~/lib




gcc -o main main.c -lstack -llinklist  

中  -lstack -llinklist   都是依赖库 ，但是-llinklist   是被依赖的库 ，gcc语法中被依赖的库一定要出现在依赖库的后面否则会出错
