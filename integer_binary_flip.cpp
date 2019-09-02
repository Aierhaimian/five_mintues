#include <iostream>

using namespace std;

class Solution{
public:
    //时间复杂度：O(N)
    // 相当于把一个数不断的右移，然后用ret不断的接收之后再左移
    // 代码简洁，思路清晰
    unsigned long reverse_bits1(const unsigned long &num)
    {
        int s = 8*sizeof(num);
        unsigned long v = num;
        unsigned long ret,i;
        for(i=0,ret=0;i<s;i++,v>>=1)
        {
            ret = (ret<<1) | (v & 1);
        }
        return ret;
    }
    // 时间复杂度：O(log(N))
    // https://blog.csdn.net/gqtcgq/article/details/50533183
    // 如果是个64位数，就按相邻的32、16、8、4、2、1进行对调
    // 调完之后的数即为所求
    unsigned long reverse_bits2(const unsigned long &num) {
        unsigned long s = 8 * sizeof(num); // bit size; must be power of 2
        unsigned long v = num;
        unsigned long mask = ~0;
        while ((s >>= 1) > 0) { // 每次分一半
            mask ^= (mask << s);
            v = ((v >> s) & mask) | ((v << s) & ~mask);
        }
        return v;
    }
};

int main()
{
    cout << Solution().reverse_bits1(52) << endl;
    cout << Solution().reverse_bits2(52) << endl;
    return 0;
}

