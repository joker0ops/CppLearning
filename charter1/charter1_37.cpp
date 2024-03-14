#include<iostream>
using namespace std;
int main(){
    /**
     * 二维数组定义：
     * 1. 数据类型 数组名[ 行数 ][ 列数 ];
     * 2. 数据类型 数组名[ 行数 ][ 列数 ] = { 
     *                                      {元素1, 元素2},
     *                                      {元素3, 元素4} 
     *                                    }; 推荐使用这一种
     * 3. 数据类型 数组名[ 行数 ][ 列数 ] = { 元素1, 元素2, 元素3, 元素4 };
     * 4. 数据类型 数组名[ ][ 列数 ] = { 元素1, 元素2, 元素3, 元素4 };
    */
   /**
    * 二维数组用途：
    * 1. 可以查看占用内存大小
    * 2. 可以查看首地址
   */
    int array[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Total size of this array: " << sizeof(array) << endl;
    cout << "First line's size of this array: " << sizeof(array[0]) << endl;
    cout << "First item's size of this array: " << sizeof(array[0][0]) << endl;
    // 打印十六进制的二维数组首地址
    cout << array << endl;
    return 0;
}