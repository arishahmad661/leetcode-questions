#include<iostream>
#include<climits>
using namespace std;

int myAtoi(string s) {
    bool positive = true;
    bool readStart = false;
    long long result = 0;

    for(char c: s){ 
        if(c == ' ' && !readStart) continue;
        else if(c <= '9' && c >= '0'){
            readStart = true;
            result = (result * 10) + (c - '0');
            if(positive && result >= INT_MAX) return INT_MAX;
            else if(!positive && -result <= INT_MIN) return INT_MIN;
        }
        else if((c == '+' || c == '-') && !readStart){ 
            if(c == '-') positive = false;
            else if(c == '+') positive = true;
            readStart = true;
        }
        else break;
    }

    return positive ? int(result) : int(-result);
}

int main(){
    string s = "   -42";
    cout << myAtoi(s) << endl; // Output: -42
    return 0;
}

