/**
 * 一维数组定义方式
 * 1. 数据类型 数组名[数组长度];
 * 2. 数据类型 数组名[数组长度] = {值1, 值2 ...};   // 若{}内元素个数不足数组长度，则剩余元素用0补全
 * 3. 数据类型 数组名[] = {值1, 值2, 值3 ...}；
 * 
 * 一维数组数组名的用途：
 * 1. 统计整个数组在内存中的长度
 * 2. 可以获取数组在内存中的首地址
*/
#include<iostream>
using namespace std;
int main(){
    // sizeof统计元素所占的内存空间大小(以字节为单位)
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "The total size of this array is: " << sizeof(arr) << endl;
    cout << "The length of this aray is: " << sizeof(arr)/sizeof(arr[0]) << endl;
    // 直接通过数组名可以访问数组首地址
    // 数组名是常量，不可以进行赋值的操作
    cout << "The first address of this array is: " << (int)arr << endl; // 十六进制转十进制
    cout << "The first item's address of this array is: " << (int)&arr[0] << endl;
    cout << "The second item's address of this array is: " << (int)&arr[1] << endl;
    return 0;
}