#include<iostream>
#include<climits>
using namespace std;

int reverse(int x) {
    int xx = x;
    long result = 0;
    while(xx != 0){
        int temp = xx % 10;
        result *= 10;
        result += temp;
        if(result > INT_MAX || result < INT_MIN) return 0;
        xx /= 10;
    }

    return (int)result;
}

int main(){
    int x = -1234567;
    cout << reverse(x) << endl; // Output: -7654321
    return 0;
}