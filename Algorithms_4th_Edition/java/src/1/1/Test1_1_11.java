public class Test1_1_11 {

    public static void printfboolarray(boolean[][] arr)
    {
        for (int i = 0; i <arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.printf("%d - %d : %c\n",i,j,arr[i][j] ? '*':' ');;
            }
        }
    }
    public static void main(String[] args) {
        boolean[][] arr = {{true,false,true},{true,false,true},{true,false,true}};
        printfboolarray(arr);
    }
}
