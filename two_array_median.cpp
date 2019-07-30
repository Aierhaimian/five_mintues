#include <iostream>
#include <vector>

using namespace std;


// 如何找到两个数组的中位数
// 给定两个已升序排序的数组A、B
// 其归并之后的大数组仍然保持升序
// 这个大数组的中位数就是这两个数组的中位数
//
// 思路一：两个数组直接归并，然后求中位数
// 那么其时间和空间复杂度都是O(m+n)
//
// 思路二：利用中位数的性质+二分查找：O(log(min(m,n)))
// 中位数左边最大的元素小于中位数右边最小元素
class Solution{
public:
    double findMedianSortedArrays(vector<int> &arrayA, vector<int> &arrayB)
    {
        int m = arrayA.size();
        int n = arrayB.size();

        if (m == 0 && n == 0)
            return 0.0;

        // 如果数组A的长度大于数组B，则交换数组
        // 否则，计算好A的i，由i计算j会使其越界
        if (m > n)
        {
            arrayA.swap(arrayB);
            swap(m, n);
        }

        int start = 0;
        int end = m;
        int mid = (m + n + 1) / 2;
        while(start <= end)
        {
            int i = (start + end) / 2;
            int j = mid - i;
            if (i<end && arrayB[j-1] > arrayA[i])
                // i偏小了，需要右移
                start = i + 1;
            else if (i > start && arrayA[i-1] > arrayB[j])
                // i偏大了，需要左移
                end = i - 1;
            else
            {
                // i刚好合适
                int maxLeft;
                if (i == 0)
                    // 数组A的元素都大于数组B
                    maxLeft = arrayB[j - 1];
                else if (j == 0)
                    // 数组A的元素都小于数组B
                    maxLeft = arrayA[i - 1];
                else
                    maxLeft = max(arrayA[i-1], arrayB[j-1]);

                if ((m+n)%2 == 1)
                    // 如果大数组长度是奇数，中位数就是
                    // 左半部分的最大值
                    return maxLeft;

                int minRight;
                if (i == m)
                    minRight = arrayB[j];
                else if (j == n)
                    minRight = arrayA[i];
                else
                    minRight = min(arrayA[i], arrayB[j]);

                // 如果大数组长度为偶数，中位数就是
                // 取左侧最大值和右侧最小值的平均
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

int main()
{
    vector<int> arr1 = {3,5,6,7,8,12,20};
    vector<int> arr2 = {1,10,17,18};
    cout << Solution().findMedianSortedArrays(arr1, arr2) << endl;
    return 0;
}

