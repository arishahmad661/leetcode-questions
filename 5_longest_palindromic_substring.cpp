#include<iostream>
using namespace std;

int exapnd(string s, size_t left, size_t right){
    while(left >= 0 && right <= s.size() - 1 && s[left] == s[right]){
        left--;
        right++;
    }
    return right - left - 1; // Length of the palindrome
}

string longestPalindrome(string s){
    size_t size = s.size();
    size_t left = 0, rifght = 0;

    for(size_t i = 0; i < size; i++){
        size_t oddSize = exapnd(s, i, i); // Odd length palindrome
        size_t evenSize = exapnd(s, i, i + 1); // Even
        size_t maxSize = max(oddSize, evenSize);

        if(maxSize > rifght - left){
            left = i - (maxSize - 1) / 2;
            rifght = i + maxSize / 2;
        }
    }
    return s.substr(left, rifght - left + 1);
}

int main(){
    string s = "racecarabc";
    string result = longestPalindrome(s);
    cout << "Longest palindromic substring: " << result << endl;
    return 0;
}