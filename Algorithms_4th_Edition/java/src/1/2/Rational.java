import java.util.Objects;

public class Rational {

    private final long numerator;
    private final long denominator;

    public Rational(long numerator, long denominator) {
        if(denominator == 0L)
            throw new IllegalArgumentException("denominator can not be 0");
        long l = gcd_sign(numerator, denominator);
        this.numerator = numerator / l;
        this.denominator = denominator / l;
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
    public Rational plus(Rational b)
    {
        long n,d;
        n = this.numerator * b.denominator + this.denominator * b.numerator;
        d = this.denominator * b.denominator;
        return new Rational(n,d);
    }

    public Rational minus(Rational b)
    {
        long n,d;
        n = this.numerator * b.denominator - this.denominator * b.numerator;
        d =this.denominator * b.denominator;
        return new Rational(n,d);
    }

    public Rational times(Rational b)
    {
        long n,d;
        n = this.numerator * b.numerator;
        d = this.denominator * b.denominator;
        return new Rational(n,d);
    }

    public Rational divides(Rational b)
    {
        long n,d;
        n = this.numerator * b.denominator;
        d = this.denominator * b.numerator;
        return new Rational(n,d);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Rational rational = (Rational) o;
        return numerator == rational.numerator && denominator == rational.denominator;
    }

    @Override
    public int hashCode() {
        return Objects.hash(numerator, denominator);
    }

    @Override
    public String toString() {
        return this.numerator + "/" + this.denominator;
    }
}
