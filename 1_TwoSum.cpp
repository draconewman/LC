#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long
#define el "\n"
#define input(v) for (auto& x : v) cin >> x
#define print(v) for (auto& x : v) cout << x << " "
ll prime = 1000000007;
ll INF = 1000000000000000000;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(N^2)
			int len=nums.size();
			// for(int i=0;i<len;i++){
			// for(int j=i+1;j<len;j++){
			// if(nums[i]+nums[j]==target){
			// return {i,j};
			// }
			// }
			// }
			// return {};

        // O(N)
        unordered_map<int,int> um;
        for(int i=0; i<len; i++){
            int numToFind = target - nums[i];
            if(um.find(numToFind) != um.end()){
                return {um[numToFind], i};
            }
            um[nums[i]] = i;
        }
        return {};
	}
};

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n);
    input(nums);
    cin >> target;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    print(result);
    return 0;
}