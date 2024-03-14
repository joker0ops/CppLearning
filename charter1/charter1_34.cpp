#include<iostream>
using namespace std;
int main(){
    /**
     * 浅析break、continue、goto
     * break为终止case并退出switch；或退出最近的一层循环
     * continue为不继续执行循环体而是执行最近循环的下一轮循环
    */
    int select = 0;
    cin >> select;
    switch (select)
    {
    case 1:
        cout << "Your choice is normal size." << endl;
        // 如若不加case语句，程序会因case穿透而继续执行下面的语句
        break;
    case 2:
        cout << "Your choice is middle size." << endl;
        break;
    case 3:
        cout << "Your choice is difficult size." << endl;
        break;
    default:
        break;
    }

    cout << "1XXXXXXX" << endl;
    cout << "2XXXXXXX" << endl;
    goto FLAG;  // 一般用大写单词代表标记，但不建议使用goto
    cout << "3XXXXXXX" << endl;
    cout << "4XXXXXXX" << endl;
    FLAG:
    cout << "5XXXXXXX" << endl;
    return 0;
}