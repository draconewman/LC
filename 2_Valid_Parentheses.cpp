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
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s)
        {
            if(i=='(' or i=='{' or i=='[') st.push(i);
            else
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();
            }
        }
        return st.empty();
        }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << (sol.isValid(s) ? "True" : "False");
    return 0;
}