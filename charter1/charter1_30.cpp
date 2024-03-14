#include <iostream>
using namespace std;
int main()
{
    /*
        while循环结构：
        先判断循环条件，为真则执行语句，为假则跳出循环
        task: 打印从0到9
    */
    int i;
    while (i < 10)
    {
        cout << i << endl;
        i++;
    }
    system("pause");
    return 0;
}