#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& num, int target) {
        vector< vector<int> > allSol;
        vector<int> sol;
        sort(num.begin(), num.end());
        kSum(num, 0, num.size() - 1, target, 4, sol, allSol);
        return allSol;
    };

    void kSum(vector<int> &num, int start, int end, int target, int k, vector<int> &sol, vector< vector<int> > &allSol) {
        if (k == 2) {
            twoSum(num, start, end, target, sol, allSol);
            return;
        }

        for (int i = start; i<end; i++)
        {
            if (i>start && num[i] == num[i - 1]) continue;
            sol.push_back(num[i]);
            kSum(num, i + 1, end, target - num[i], k - 1, sol, allSol);
            sol.pop_back();
        }
    };

    void twoSum(vector<int> &num, int start, int end, int target, vector<int> &sol, vector< vector<int> > &allSol) {
        while (start<end)
        {
            int sum = num[start] + num[end];
            if (sum == target) {
                sol.push_back(num[start]);
                sol.push_back(num[end]);
                allSol.push_back(sol);
                sol.pop_back();
                sol.pop_back();
                start++;
                end--;
                while (num[start] == num[start - 1]) start++;
                while (num[end] == num[end + 1]) end--;
            }
            else if (sum<target)
                start++;
            else
                end--;
        }
    };
};

int main(void)
{
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    vector< vector<int> > ans;
   
    Solution s;
    ans = s.fourSum(v, 0);
    
    for (int i=0; i<ans.size(); i++)
    {
        for (int j=0; j<ans[i].size(); j++)    
            cout << ans[i][j] << ", ";

        cout<<endl;
    }

    return 0;
}

