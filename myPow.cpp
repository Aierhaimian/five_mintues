#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int pow(const int &m1, const int &n1)
{
    int m = m1;
    int n = n1;
    int res = 1;
    if (m == 0)
        return 0;
    else if (n == 0)
        return 1;
    else {
        while (n > 0)
        {
            if (res*m < 0)
            {
                cout << "The result is overflow!" << endl;
                return -1;
            }
            else
                res *= m;
            n--;
        }
    }
    return res;
}

int genRes(int m, int n)
{
    if (n == 1)
        return m;
    
    int res1 = genRes(m , n/2);
    if (n%2 == 0 && res1*res1 < 0)
    {
        cout << "overflow" << endl;
        exit(-1);
    }
    else if (n%2 == 1 && res1*res1*m < 0){
        cout << "overflow" << endl;
        exit(-1);
    }
    
    
    if (n%2 == 1)
        return res1*res1*m;
    return res1*res1;
}

int pow2(const int &m1, const int &n1)
{
    int m = m1;
    int n = n1;
    int res = 0;
    if (m == 0)
        return 0;
    else if (n == 0)
        return 1;
    else {
        res = genRes(m, n);
    }
    return res;
}



int main() {
    int m = 0, n = 0;
    cout << pow2(m, n) << endl;
    int m1 = 0, n1 = 1;
    cout << pow2(m1, n1) << endl;
    int m2 = 1, n2 = 0;
    cout << pow2(m2, n2) << endl;
    int m3 = 4, n3 = 2;
    cout << pow2(m3, n3) << endl;
    int m5 = 4, n5 = 3;
    cout << pow2(m5, n5) << endl;
    int m4 = 12345, n4 = 456788;
    cout << pow2(m4, n4) << endl;
    
    return 0;
}
