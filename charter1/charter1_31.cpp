    /*
    系统自动生成随机数让玩家猜
    猜对了直接结束
    猜错了提示猜大了还是猜小了
    */
#include<iostream>
#include<ctime>
using namespace std;
int main(){
    int num, testnum;
    // 为rand函数加入时间种子防止每次rand()返回的数都是相同的
    srand((unsigned int)time(NULL));
    // 使用rand()伪随机函数生成一个数字，并使用%100将该数字的范围限制在0~99的范围之间，再使用+1将范围扩大到1~100
    num = rand()%100 + 1;
    cout << "Please input a number: ";
    cin >> testnum;
    while(num!=testnum){
        if(num>testnum)
            cout << "value is lower than num" << endl;
        else
            cout << "value is bigger than num" << endl;
        cout << "Please input a number: ";
        cin >> testnum;
    }
    cout << "Successfully!" << endl;
    return 0;
}