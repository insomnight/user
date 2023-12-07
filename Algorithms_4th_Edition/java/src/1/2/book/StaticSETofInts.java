import java.util.Arrays;
import java.util.stream.IntStream;

public class StaticSETofInts {
    private int[] a;

    public StaticSETofInts(int[] keys)
    {
        a = new int[keys.length];
        IntStream.range(0, keys.length).forEach(i -> a[i] = keys[i]);
        Arrays.sort(a);
    }

    public boolean contains(int key)
    {return rank(key)!= -1;}

    private int rank(int key) {
        int lo = 0;
        int hi = a.length - 1;
        int mid;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(key > a[mid]) lo = mid + 1;
            else if(key < a[mid]) hi = mid - 1;
            return mid;
        }
        return -1;
    }
}
