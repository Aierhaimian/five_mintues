#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* 请编写一个程序，按照升序对栈进行排序（即最大元素位于栈顶），要求
 * 最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据
 * 结构中。
 *
 * 给定一个vector<int> numbers，其中第一个元素为栈顶，请返回排序后的
 * 栈。请注意这是一个栈，意味着排序过程中你只能访问到最后一个元素。*/
class Solution{
public:
    vector<int> twoStackSort(vector<int> &vec)
    {
        vector<int> res;
        if (vec.size() == 0)
            return res;
        
        // 构建初始化栈和辅助栈，并初始化原始栈
        stack<int> initStk, tempStk;
        for (int i=vec.size()-1; i>=0; --i)
            initStk.push(vec[i]);

        while (!initStk.empty())
        {
            if (tempStk.empty())
            {
                tempStk.push(initStk.top());
                initStk.pop();
            }
            else
            {
                // 新建变量，存储原始栈中待排序的栈顶元素
                int temp = initStk.top();
                initStk.pop();

                while (!tempStk.empty() && tempStk.top() > temp)
                {
                    initStk.push(tempStk.top());
                    tempStk.pop();
                }

                //辅助栈存储之前保存的变量
                tempStk.push(temp);
            }
        }

        while(!tempStk.empty())
        {
            res.push_back(tempStk.top());
            tempStk.pop();
        }

        return res;
    }
};

int main()
{
    vector<int> vec = {3,8,1,7,2,10,5,12};
    vector<int> res;
    res = Solution().twoStackSort(vec);
    for (int i: res)
        cout << i << " ";
    cout << endl;
    return 0;
}

