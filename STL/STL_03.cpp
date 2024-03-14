/**
 * string容器
 * string是C++风格的字符串，本质上是一个类
 * string和char* 区别：
 * char* 是一个指针
 * string是一个类，其内部封装了char*
 */
#include <iostream>
#include <string>
using namespace std;

// string构造
void test01()
{
    // string();
    // 调用无参构造函数创建空字符串
    string s1;
    cout << "str1 = " << s1 << endl;

    // string(const char* str);
    // 调用有参构造函数，使用C风格字符串初始化s
    const char *str = "Hello World";
    string s2(str); // 把C风格字符串转换为string类型字符串
    cout << "str2 = " << s2 << endl;

    // string(const string& str);
    string s3(s2); // 调用拷贝构造函数
    cout << "str3 = " << s3 << endl;

    // string s4(int num, char c);
    string s4(4, 'c'); // 调用有参构造函数，使用num个字符c初始化字符串s4
    cout << "str4 = " << s4 << endl;
}

// string赋值
void test02()
{
    // string& operator=(const char* s);
    // 重载=运算符，把C风格字符串赋值给当前字符串
    string str1;
    str1 = "Hello World";
    cout << "str1 = " << str1 << endl;

    // string& operator=(const string& s);
    // 重载=运算符，实现两个string类型字符串之间的赋值操作
    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    // string& operator=(const char c);
    // 重载=运算符，将字符赋值给当前字符串
    string str3;
    str3 = 'c';
    cout << "str3 = " << str3 << endl;

    // string& assign(const char* s);
    // 把C风格字符串赋值给当前字符串
    string str4;
    str4.assign("Hello C++");
    cout << "str4 = " << str4 << endl;

    // string& assign(const char* s, int n);
    // 把C风格字符串的前n个字符赋值给当前字符串
    string str5;
    str5.assign("Hello C++", 5);
    cout << "str5 = " << str5 << endl;

    // string& assign(const string& s);
    // 把string类型字符串str5赋值给当前字符串
    string str6;
    str6.assign(str5);
    cout << "str6 = " << str6 << endl;

    // string& assign(int n, char c);
    // 把n个字符c赋值给当前字符串
    string str7;
    str7.assign(5, 'c');
    cout << "str7 = " << str7 << endl;
}

// string字符串拼接
void test03()
{
    string str1 = "I";
    // string& operator+=(const char* str);
    // 重载+=运算符实现C风格字符串与str1的拼接
    str1 += " love playing games";
    // string& operator+=(const char c);
    str1 += ':';
    // string& operator+=(const string& str);
    string str2 = " This is";
    str1 += str2;
    // string& append(const char* s);
    // 将C风格字符串拼接到当前字符串
    const char *str = " very";
    str1.append(str);
    // string& append(const char* s, int n);
    // 将C风格字符串的前n个字符拼接到当前字符串
    const char *s = " cool!!!!!";
    str1.append(s, 5);
    // string& append(const string &s);
    // 将string类型字符串拼接到当前字符串
    string str3 = "!!!";
    str1.append(str3);
    // string& append(const string& s, int pos, int n);
    // 字符串s中从pos开始的n个字符拼接到当前字符串
    string str4 = "DDDDDamn it!";
    str1.append(str4, 5, 8);
}

// string字符串查找和替换
void test04()
{
    // int find(const string& str, int pos = 0) const;          // 从默认参数pos开始查找str第一次出现的位置，返回位置或-1
    // int find(const char* s, int pos = 0) const;              // 同上
    // int find(const char* s, int pos, int n) const;           // 从pos开始查找s的前n个字符第一次出现的位置，返回位置或-1
    // int find(const char c, int pos = 0) const;               // 从默认参数pos开始查找字符c第一次出现的位置，返回位置或-1
    // int rfind(const string& str, int pos = npos) const;      // 从pos开始查找str最后一次出现的位置，返回位置或-1
    // int rfind(const char* str, int pos = npos) const;        // 同上
    // int rfind(const char* str, int pos, int n) const;        // 从pos开始查找str的前n个字符最后一次出现的位置，返回位置或-1
    // int rfind(const char c, int pos = 0) const;              // 从默认参数pos开始查找字符c最后一次出现的位置
    // string& replace(int pos, int n, const string& str);      // 替换从pos开始n个字符为字符串str
    // string& replace(int pos, int n, const char* str);        // 同上

    // 查找
    string str1 = "abcdefghigkdelmnopq";
    int pos = str1.find("de");
    if (pos == -1)
        cout << "Didn't find!" << endl;
    else
        cout << "pos = " << pos << endl;

    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;

    // 替换
    string str2 = "abcdefg";
    str2.replace(1, 3, "111111");
    cout << "str1 = " << str1 << endl;
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    return 0;
}