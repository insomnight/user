public class Rational {

    private long numerator;
    private long denominator;

    public Rational(long numerator, long denominator) {
        if(denominator == 0L)
            throw new IllegalArgumentException("denominator can not be 0");
        this.numerator = numerator;
        this.denominator = denominator;
    }

   public static long gcd(long p, long q)
   {
        if(q == 0) return p;
        long r = p % q;
        return gcd(q,r);
   }

   public static long gcd_sign(long p, long q)
   {
       long result = gcd(Math.abs(p),Math.abs(q));
       if(q < 0L && p < 0L)
           return -result;
       else
           return result;
   }
    public Rational plus(Rational b);
    {
    }

    public Rational minus(Rational b);
    {
    }

    public Rational times(Rational b);
    {
        long gcd_num,numerator,denominator;

        numerator = a->numerator * b->numerator;
        denominator = a->denominator * b->denominator;

        gcd_num = gcd_sign(numerator,denominator);
        r->numerator = numerator / gcd_num;
        r->denominator = denominator / gcd_num;
        return r;
    }

    Rational * divides(Rational * r, const Rational * a, const Rational * b);
    {
        long gcd_num,numerator,denominator;

        numerator = a->numerator * b->denominator;
        denominator = a->denominator * b->numerator;

        gcd_num = gcd_sign(numerator,denominator);
        r->numerator = numerator / gcd_num;
        r->denominator = denominator / gcd_num;
        return r;
    }

    int rationalEquals(const Rational * a,const Rational * b)
    {
        return ( (a->numerator / b->numerator) / (a->denominator / b->denominator) ) == 1;
    }

    char * rationalToString(const Rational * a, char * str, size_t n)
    {
        snprintf(str,n,"%ld/%ld",a->numerator,a->denominator);
        return str;
    }
}
