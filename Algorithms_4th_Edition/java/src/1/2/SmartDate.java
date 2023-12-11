import java.util.Objects;

public class SmartDate {

    private final int year;
    private final int month;
    private final int day;

    private static final int[] monthDay = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    private static final int[] day_of_weeks = {6,7,1,2,4,5,6};
    private static final int[] day_of_weeks_r = {6,5,4,3,2,1,7};

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

    public int dayOfTheWeek()
    {
        int daysdiff = 0;
        if(year() >= 2000 )
        {
            for(int i = 2000; i < year(); i++)
                daysdiff += isLeapYear(i) ? 366 : 365;
            for(int i = 1; i < month(); i++)
                daysdiff += isLeapYear(year()) && i == 2 ? monthDay[i] + 1 : monthDay[i];
            daysdiff += day();
            daysdiff -= 1;
            return day_of_weeks[daysdiff % 7];
        } else {
            for(int i = year() + 1; i < 2000; i++)
                daysdiff += isLeapYear(i) ? 366 : 365;
            for(int i = month() + 1; i <= 12; i++)
                daysdiff += isLeapYear(year()) && i == 2 ? monthDay[i] + 1 : monthDay[i];
            daysdiff += isLeapYear(year()) && month() == 2 ? monthDay[month()] + 1 - day() : monthDay[month()] - day();
            daysdiff++;
            return day_of_weeks_r[daysdiff % 7];
        }
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
