public class Test1_1_13 {

    public static void printreverse(int[][] arr)
    {
        for (int i = 0; i < arr[0].length; i++) {
            for (int j = 0; j < arr.length; j++) {
                System.out.printf("%d ",arr[j][i]);
            }
        }
    }
}
