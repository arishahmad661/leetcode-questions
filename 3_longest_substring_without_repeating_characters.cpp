#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s){
    int size = s.size();
    int p1 = 0, p2 = 0, result = 0;
    unordered_set<char> set;
    while(p1 < size && p2 < size){
        if(set.find(s[p2]) == set.end()){
            set.insert(s[p2]);
            result = max(result, p2 - p1 + 1);
            p2++;
        }else{
            while(p1 < p2 && set.find(s[p2]) != set.end()){
                set.erase(s[p1]);
                p1++;
 `           }
            set.insert(s[p2]);
        }
        p2++;
    }
    return result;
}

int main(){
    string s = "asdxhawdhcfaguswdcbiuwdcbihkawsdbcailhdfbvl";
    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    return 0;
}