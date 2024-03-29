/**
 * STL基础：
 * STL从广义上分为：容器(Container)、算法(Algorithm)、迭代器(Iterator)
 * 容器和算法之间通过迭代器进行无缝衔接
 * STL分为六大组件：容器、算法、迭代器、仿函数、适配器、空间配置器
 * 
 * 1.容器：
 * 将最广泛的数据结构实现出来，分为序列式容器和关联式容器两种
 * 序列式容器强调值的排序，容器中每个元素都有固定的位置
 * 关联式容器类似二叉树结构，各个元素之间没有严格的物理上的顺序关系
 * 
 * 2.算法：
 * 用有限的步骤解决某一逻辑或数学问题的方法
 * 质变算法：运算过程中会更改区间内元素的内容，例如拷贝、替换、删除等。
 * 非质变算法：运算过程中不会更改区间内元素的内容，例如查找、计数、遍历、寻找极值等等。
 * 
 * 3.迭代器：
 * 容器和算法之间的粘合剂
 * 提供一种方法，使之能够依序寻访某个容器内所含的各个元素，而又无需暴露该容器的内部表示方式
 * 每个容器都有自己专属的迭代器，类似于指针
 * 
 * 输入迭代器       对数据的只读访问               只读，支持++、==、!=
 * 输出迭代器       对数据的只写访问               只写，支持++
 * 前向迭代器       读写操作，并能向前推进迭代器    读写，支持++、==、!=
 * 双向迭代器       读写操作，并能向前和向后操作    读写，支持++、--
 * 随机访问迭代器   读写操作，随机访问任意数据      读写，支持++、--、[n]、-n、<、<=、>、>=
 * !!!常用的迭代器种类为双向迭代器和随机访问迭代器
 * 
*/