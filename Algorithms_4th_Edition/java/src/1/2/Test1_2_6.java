public class Test1_2_6 {

    public static boolean circular_rotation(String a, String b)
    {
        return a.length() == b.length() && b.concat(b).contains(a);
    }

    public static void main(String[] args) {
        if(circular_rotation(args[0],args[1]))
            System.out.println("yes");
        else
            System.out.println("no");
    }
}
