#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result(2);
    unordered_map<int, int> umap;
    for (size_t i = 0; i < nums.size(); i++) {
        int temp = target - nums[i];
        if(umap.find(temp) != umap.end()){
            return {umap[temp], static_cast<int>(i)};
        }else{
            umap[nums[i]] = i;
        }
    }
    return {};
}

int main(){

    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    if (result.empty()) {
        cout << "No two numbers add up to " << target << endl;
        return 0;
    }
    cout << "Indices of the two numbers that add up to " << target << " are: " << result[0] << " and " << result[1] << endl;

}