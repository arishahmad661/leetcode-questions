#include<iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x/10 == 0) return true;

    long long temp = 0, xx = x;
    while(x){
        temp = (temp * 10) + (x % 10);
        x /= 10;
    }

    return temp == xx;
}

int main(){
    int x = 121;
    cout << (isPalindrome(x) ? "true" : "false") << endl;
    return 0;
}