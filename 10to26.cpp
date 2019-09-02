#include <iostream>
#include <string>

using namespace std;

// 题目：在Excel中，第一列用A表示，第二列用B表示...第26列用Z表示，第27列用AA表示，
//       第28列用AB表示...依次类推。请写出一个函数，输入一个数表示第几列，输出用字母
//       表示的列号编码。
// 题意：十进制转二十六进制
// 思路：用输入的数字cols模26得到temp，temp即为二十六进制数字的最后一位，用temp + 'A' - 1
//       即可得到所对应的A~Z中的字母；接着用输入的数字cols除以26，用这个结果继续寻找倒数第
//       二位所对应的字符，直到cols为0。但是，temp=0的时候比较特殊，比如输入的数字cols=26，
//       cols%26=0，本来应该输出Z，结果输出的是@，所以把temp=0的情况单独拿出来判断一下，当
//       temp=0时，置temp=26，然后将cols-1，这时输入26将会得到正确答案Z。

class Solution{
public:
    string ExcelEncode(int x)
    {
        string res;
        while(x)
        {
            int tmp = x % 26;
            x = x / 26;
            if (tmp == 0)
            {
                tmp = 26;
                x = x - 1;
            }
            res.push_back((char)('A'+tmp-1));
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    cout << Solution().ExcelEncode(18280) << endl;
    cout << Solution().ExcelEncode(702) << endl;
    return 0;
}

