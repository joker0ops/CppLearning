#include <iostream>
using namespace std;
int main()
{
    /**
     * 算法1：一维数组寻找最大值
     */
    int array[10] = {34, 350, 200, 0, 1, 3, 45, 90, 100, 1000};
    int max = array[0];
    for (int i = 0; i < 10; i++)
    {
        if (array[i] >= max)
            max = array[i];
    }
    cout << "The max number is: " << max << endl;
    /**
     * 算法2：数组元素逆置
     */
    int temp;
    for (int i = 0, j = sizeof(array) / 4 - 1; i >= j; i++, j--)
    {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    for (int i = 0; i < 10; i++)
        cout << array[i] << " ";
    cout << endl;
    /**
     * 算法3：冒泡排序
     * 1. 比较相邻的元素。如果不符合排序规则则交换他们两个。
     * 2. 对每一对相邻元素做同样的工作，把最大(最小)值冒泡到后面。
     * 若规则为从小到大————那么每一轮中最大的一个值一定冒泡到该轮最后
     * 若规则为从大到小————那么每一轮中最小的一个值一定冒泡到该轮最后
     * 3. 重复以上的步骤，每次比较次数-1，直到只剩下一个元素不需要比较。
     */
    // i控制外层循环的比较轮数，只需要比较length(array)-1次，最后剩下一个元素不用比较
    for (int i = 0; i < 10; i++)
    {
        // j控制内循环两两比较，每次将最大(最小)元素冒泡到本轮最后一位之后，下一轮需比较的元素-1，j最大取到数组的倒数第二位
        for (int j = 0; j < sizeof(array) / 4 - 1 - i; j++)
        {
            if (array[j] >= array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < sizeof(array) / 4; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}