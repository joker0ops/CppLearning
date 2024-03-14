/**
 * 容器：vector
 * 算法：for_each
 * 迭代器：vector<int>::iterator
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void MyPrint(int val)
{
    cout << val << endl;
}

void test01()
{
    // 创建vector容器，并通过模板参数指定容器中存放的数据类型
    vector<int> v;
    // 向容器中存放数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // 每一个容器都有自己的迭代器，迭代器用来遍历容器中的元素
    // v.begin() 返回迭代器，这个迭代器指向容器中第一个数据
    // v.end() 返回迭代器，这个迭代器指向容器中最后一个元素的下一个位置
    // vector<int>::iterator 拿到vector<int>这种容器的迭代器类型

    vector<int>::iterator Start = v.begin();
    vector<int>::iterator End = v.end();
    cout << 1 << endl;
    // 第一种遍历方式：
    while (Start != End)
    {
        cout << *Start << endl;
        Start++;
    }
    cout << 2 << endl;
    // 第二种遍历方式：
    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        cout << *i << endl;
    }
    cout << 3 << endl;
    // 第三种遍历方式：
    // 使用STL提供的标准遍历算法，头文件Algorithm
    for_each(v.begin(), v.end(), MyPrint);
}

// 存放自定义数据类型
class Person
{
public:
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
    }

public:
    string mName;
    int mAge;
};
void test02()
{
    // 存放对象
    vector<Person> v;
    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin(); it < v.end(); it++)
    {
        cout << "Name: " << (*it).mName << "Age: " << (*it).mAge << endl;
    }
    // 存放指针
    vector<Person *> v2;
    v2.push_back(&p1);
    v2.push_back(&p2);
    v2.push_back(&p3);
    v2.push_back(&p4);
    v2.push_back(&p5);

    for (vector<Person *>::iterator it = v2.begin(); it < v2.end(); it++)
    {
        cout << "Name: " << (*it)->mName << "Age: " << (*it)->mAge << endl;
    }
}

void test03()
{
    // 容器嵌套容器————二维数组
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
        v3.push_back(i + 2);
        v4.push_back(i + 3);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator i = v.begin(); i < v.end(); i++)
    {
        for (vector<int>::iterator j = (*i).begin(); j < (*i).end(); j++)
        {
            cout << (*j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    test01();
    test02();
    test03();
    return 0;
}