public class Test1_1_22 {
    public static int rank(int key,int[] a)
    {
        return rank(key,a,0,a.length - 1,0);
    }

    public static int rank(int key,int[] a,int lo,int hi,int deep)
    {
        System.out.printf("lo = %d, hi = %d, deep = %d\n",lo,hi,deep);
        if(lo > hi) return -1;
        int mid = (lo + hi) / 2;
        if(a[mid] > key) return rank(key,a,lo,mid - 1,deep + 1);
        else if(a[mid] < key) return rank(key,a,mid + 1,hi,deep + 1);
        else return  mid;
    }
}
