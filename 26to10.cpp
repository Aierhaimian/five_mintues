#include <iostream>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

typedef unsigned long long ULL;

// 题目：在Excel中，用A表示第一列，B表示第二列...Z表示第26列，AA表示第27列，
//       AB表示第28列...依次列推。请写出一个函数，输入用字母表示的列号编码，
//       输出它是第几列。
// 题意：二十六进制转十进制
// 思路：将输入的字符串先转换成字符数组，遍历数组中的每一个字符，用这个字符
//       减去A再加1就是该位对应的十进制数，然后乘以26的相应次方，最后把这些
//       数加起来就是结果了。
// 细节：需要注意输入字符串中有非法字符怎么办？-> 遇见非法字符退出
//       需要注意转换后的数溢出怎么办？-> 使用 unsigned long long 并加溢出判断
//       尽量加const
class Solution{
public:
    ULL ExcelEncod(const string &str)
    {
        int len = str.size();
        if (len > 15)
        {
            cerr << "The line number may overflow..." << endl;
            exit(-1);
        }
        int exp = len - 1;
        ULL res = 0;
        for (char c: str)
        {
            if (c < 'A' || c > 'Z')
            {
                cerr << "The input str is wrong!" << endl;
                exit(-1);
            }
            ULL tmp = (c - 'A' + 1)*pow(26,exp);
            if (res > ULLONG_MAX - tmp)
            {
                cerr << "The number is overflow!" << endl;
                exit(-1);
            }
            else
                res += (c - 'A' + 1)*pow(26, exp);
            -- exp;
        }

        return res;
    }
};

int main()
{
    string str = "AAAB";
    cout << Solution().ExcelEncod(str) << endl;
    return 0;
}

