#include<iostream>
using namespace std;

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int& a,int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}