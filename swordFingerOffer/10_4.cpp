// https://blog.csdn.net/qq_41453285/article/details/108060505
int numWays(int n) {
    if(n == 0 || n == 1) return 1;
    int N = 0, NMinusOne = 1, NMinusTwo = 1;

    while(n >= 2)
    {
        // 采取从下往上的方法，把计算过的中间项保存起来，避免重复计算导致递归调用栈溢出
        
        N = NMinusOne + NMinusTwo;
        NMinusTwo = NMinusOne;
        NMinusOne = N;
        n --;
    }

    return N;
}
