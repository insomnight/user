public class SmallDate extends Date {

    private final int value;

    public SmallDate(int m,int d,int y) {
        this.value = y * 512 + m * 32 + d;
    }

    @Override
    public int month() {
        return (value / 32) % 16;
    }

    @Override
    public int day() {
        return value % 32;
    }

    @Override
    public int year() {
        return value / 512;
    }
}
