import java.util.Objects;

public class BasicDate extends Date {

    private final int year;
    private final int month;

    public BasicDate(int m,int d, int y) {
        this.year = y;
        this.month = m;
        this.day = d;
    }

    private final int day;

    @Override
    public int month() {
        return month;
    }

    @Override
    public int day() {
        return day;
    }

    @Override
    public int year() {
        return year;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        BasicDate basicDate = (BasicDate) o;
        return year == basicDate.year && month == basicDate.month && day == basicDate.day;
    }

    @Override
    public int hashCode() {
        return Objects.hash(year, month, day);
    }
}
