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
}
