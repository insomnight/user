public class Test1_1_29 {
    public static int rank(int key, int[] a,int lo,int hi)
    {  // 数组必须是有序的
        if(lo > hi) return -1;
        int mid = lo + (hi - lo)/2;
        if(key < a[mid]) return rank(key,a,lo,mid - 1);
        else if(key > a[mid]) return rank(key,a,mid + 1,hi);
        else return mid;
    }

    public static int rank(int key,int[] a)
    {
        int mid = rank(key,a,0,a.length - 1);
        for (; mid > 0 && a[mid] == a[mid - 1]; mid--)
            continue;
        return mid;
    }

    public static int count(int key,int[] a)
    {
        int mid = rank(key,a,0,a.length - 1);
        if(mid == -1)
            return -1;
        int cnt = 1;
        for (int i = mid; i > 0 && a[mid] == a[mid - 1] ; i--)
            cnt++;
        for (int i = mid; i < a.length - 1 && a[mid] == a[mid + 1] ; i++)
            cnt++;
        return cnt;
    }
}
