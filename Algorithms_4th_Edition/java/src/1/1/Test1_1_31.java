import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdRandom;

public class Test1_1_31 {

    public static void main(String[] args) {
        // 初始化画布
        StdDraw.setXscale(-5.0,5.0);
        StdDraw.setYscale(-5.0,5.0);
        drawCircle();
        int n = Integer.parseInt(args[0]);
        double p = Double.parseDouble(args[1]);

        Coordinate[] arr = getCirclePoint(0,0,4,n);
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setPenRadius(0.05);
        for (int i = 0; i < n; i++) {
            StdDraw.point(arr[i].getX(),arr[i].getY());
        }

        StdDraw.setPenRadius();
        StdDraw.setPenColor(StdDraw.GRAY);
        StdRandom.setSeed(System.currentTimeMillis());
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++) {
                if(StdRandom.uniformDouble() < p)
                    StdDraw.line(arr[i].getX(),arr[i].getY(),arr[j].getX(),arr[j].getY());
            }
    }

    /**
     * 计算得到圆上n个等距点的坐标
     * @param x 圆心的x坐标
     * @param y 圆心的y坐标
     * @param r 圆的半径
     * @param n 圆上等距点数量
     * @return 返回n个等距点坐标数组
     */
    public static Coordinate [] getCirclePoint(double x,double y,double r,int n)
    {
        Coordinate[] arr = new Coordinate[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Coordinate(x + r * Math.cos(2 * Math.PI / n * i),y + r * Math.sin(2 * Math.PI / n * i));
        }
        return arr;
    }
    public static void drawCircle()
    {
        StdDraw.setPenColor(StdDraw.BLUE);
        StdDraw.circle(0.0,0.0,4.0);
    }

    static class Coordinate
    {
        private double x;
        private double y;

        public Coordinate() {
            this(0,0);
        }

        public Coordinate(double x) {
            this(x,0);
        }

        public Coordinate(double x, double y) {
            this.x = x;
            this.y = y;
        }

        public double getX() {
            return x;
        }

        public void setX(double x) {
            this.x = x;
        }

        public double getY() {
            return y;
        }

        public void setY(double y) {
            this.y = y;
        }
    }
}
