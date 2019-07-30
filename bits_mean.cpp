#include <iostream>

using namespace std;

// 不会产生高位溢出的求平均数方法
// 将数分成三类分别计算平均数的思路：
// 1. 两数对应位位1的，通过按位与操作计算，因为两个1相加等于2，
//    在求平均还是等于1；
// 2. 两个数对应位是1和0的，通过按位异或提取，之后再右移一位，
//    那么相当于求平均
// 3. 两个数对应位为0的，不用求。
class Solution{
public:
    int bitsMean(int &x, int &y)
    {
        return (x&y) + ((x^y)>>1);
    }
};

int main()
{
    int x = 8;
    int y = 10;
    cout << Solution().bitsMean(x, y) << endl;
    return 0;
}

