public class Test1_1_14 {
    public static int lg(int n)
    {
        if(n <= 0)
            throw new IllegalArgumentException("lg的参数要大于0,当前参数:" + n);
        int result =1;
        for (int i = 2; i < n; i *= 2)
            result++;
        return result;
    }
}
