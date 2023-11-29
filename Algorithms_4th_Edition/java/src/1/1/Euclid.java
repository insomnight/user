public class Euclid {

    public static int gcd(int p,int q)
    {
        System.out.printf("p = %d, q = %d\n",p,q);
        if(q == 0) return p;
        int r = p % q;
        return gcd(q,r);
    }

    public static void main(String[] args) {
        if(args.length < 2)
            throw new IllegalArgumentException("参数数量不对:");
        int p = Integer.parseInt(args[0]);
        int q = Integer.parseInt(args[1]);
        System.out.printf("p = %d, q = %d,result = %d\n",p,q,gcd(p,q));
    }
}
