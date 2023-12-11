import java.util.Objects;

public class SmartDate {

    private final int year;
    private final int month;
    private final int day;

    private static final int[] monthDay = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    public static boolean isLeapYear(int y)
    {
        return ( y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

    public SmartDate(int m, int d, int y) {
        if(m < 1 || m > 12)
            throw new IllegalArgumentException("the month " + m + " not in the 1 to 12 range");

        if(isLeapYear(y) && m == 2 && (d < 1 || d > 29))
            throw new IllegalArgumentException("the day "+ d +" not in the 1 to 29 range");

        if(d < 1 || d > monthDay[m])
            throw new IllegalArgumentException("the day "+ d +" not in the 1 to " + monthDay[m] + " range");

        this.year = y;
        this.month = m;
        this.day = d;
    }
    public int month() {
        return month;
    }

    public int day() {
        return day;
    }

    public int year() {
        return year;
    }

    @Override
    public String toString() {
        return month() + "/" + day() +"/" +year();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        SmartDate basicDate = (SmartDate) o;
        return year == basicDate.year && month == basicDate.month && day == basicDate.day;
    }

    @Override
    public int hashCode() {
        return Objects.hash(year, month, day);
    }
}
