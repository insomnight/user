public class Test1_1_20 {

    public static double lnN(int n)
    {
        if(n == 1) return Math.log((double) 1);
        return Math.log((double) n) + lnN(n-1);
    }

    public static void main(String[] args) {
        for (int i = 1; i < 100; i++) {
            System.out.println(i + " " + lnN(i));
        }
    }
}
