#include <iostream>
#include <vector>

using namespace std;

// 求N个整数的平均值
class Solution{
public:
    int avg(const vector<int> &arr)
    {
        int ans = 0, res = 0;
        int N = arr.size();
        for(int i: arr)
        {
            ans += i/N;
            res += i%N;
            ans += res/N;
            res = res%N;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1,2,3,4,5};
    cout << Solution().avg(arr) << endl;
    return 0;
}

