/**
 * 猜数字的do...while()解法，比while循环更加简单易懂
*/
#include<iostream>
#include<ctime>
using namespace std;
int main(){
    int num, val;
    srand((unsigned int)time(NULL));
    num = rand()%100+1;
    // 不论任何条件先执行一次循环体
    do{
        cout << "Please input a number: ";
        cin >> val;
        if(val > num)
            cout << "This number is bigger than it." << endl;
        else if(val < num)
            cout << "This number is lower than it." << endl;
    }while(val != num);
    cout << "Successfully!";
    return 0;
}