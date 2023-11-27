public class Test1_1_3 {
    public static boolean threeCompar(int a, int b, int c)
    {
        return a == b && b == c;
    }
    public static void main(String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int c = Integer.parseInt(args[2]);

        if(threeCompar(a,b,c))
            System.out.println("equal");
        else
            System.out.println("not equal");
    }
}
