public class DateTest {

    public static void main(String[] args) {
        int m = Integer.parseInt(args[0]);
        int d = Integer.parseInt(args[1]);
        int y = Integer.parseInt(args[2]);
        Date date = new SmallDate(m,d,y);
        System.out.println(date);
        date = new BasicDate(m,d,y);
        System.out.println(date);
    }
}
