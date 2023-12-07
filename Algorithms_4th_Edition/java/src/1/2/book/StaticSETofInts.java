import java.lang.reflect.Array;
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
    {return rank(key)!= -1}

    private int rank(int key) {

    }
}
