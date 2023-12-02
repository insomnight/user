public class Matrix {

    public static double dot(double[] x, double[] y)
    {
        if(x.length != y.length)
            throw new IllegalArgumentException("两个矩阵的长度不一样: x.length = "+x.length+" y,length = "+y.length);
        double result = 0.0;
        for (int i = 0; i < x.length; i++) {
            result += x[i] * y[i];
        }
        return result;
    }
    
    public static double[][] mult(double[][] a, double[][] b)
    {
        if(a[0].length != b.length)
            throw new IllegalArgumentException("矩阵a,列数为 " + a[0].length + " b的行数为 "+b.length+" 不相等!");
        double[][] result = new double[a.length][b[0].length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b[0].length; j++) {
                result[i][j] = 0.0;
                for(int k = 0; k < b.length; k++)
                    result[i][j] += a[i][k] * b[k][j];
            }
        }
        return result;
    }

    public static double[][] transpose(double[][] a)
    {
        double [][] result = new double[a[0].length][a.length];
        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                result[i][j] = a[j][i];
            }
        }
        return result;
    }

    public static double[] mult(double[][] a,double[] x)
    {
        if(a[0].length != x.length)
            throw new IllegalArgumentException("矩阵a,列数为 " + a[0].length + " x的行数为 "+x.length+" 不相等!");
        double [] result = new double[a.length];
        for (int i = 0; i < a.length; i++) {
            result[i] = 0.0;
            for (int j = 0; j < a[i].length; j++) {
                result[i] += a[i][j] * x[j];
            }
        }
        return result;
    }

    public static double[] mult(double[] y, double [][] a)
    {
        if(y.length != a.length)
            throw new IllegalArgumentException("矩阵a,列数为 " + a[0].length + " y的行数为 "+y.length+" 不相等!");
        double [] result = new double[a[0].length];
        for (int i = 0; i < result.length; i++) {
            result[i] = 0.0;
            for (int j = 0; j < a.length; j++) {
                result[i] += y[j] * a[j][i];
            }
        }
        return result;
    }
}
