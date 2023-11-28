public class Test1_1_15 {
    public static int [] histogram(int a[],int m)
    {
        int[] result = new int[m];
        for (int i = 0; i < a.length; i++)
            if(a[i] >= 0 && a[i] < m)
                result[a[i]]++;
        return result;
    }
}
