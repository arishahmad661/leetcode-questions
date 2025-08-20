#include<iostream>
#include<vector>
#include<string>
using namespace std;

string convert(string s, int numRows){
    if(numRows <=1 || numRows >= s.size()) return s;

    vector<vector<char>> arr(numRows);
    int index = 0, order = 1;
    string result;

    for(char c:  s){
        arr[index].push_back(c);
        if(index == 0) order = 1;
        else if(index == numRows -1) order = -1;
        index += order;
    }
    
    for(auto row: arr){
        for(char c: row){
            result += c;
        }
    }
    return result;
}

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = convert(s, numRows);
    cout << "Zigzag conversion: " << result << endl;
    return 0;
}