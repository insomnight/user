public class Counter {

    private final String name;
    private int count;

    /**
     * 创建一个名为id的计数器
     * @param id 计数的名
     */
    public Counter(String id) {
        this.name = id;
    }

    /**
     * 将计数器的值加一
     */
    public void increment(){
        this.count++;
    }

    public int tally(){
        return this.count;
    }

    @Override
    public String toString() {
        return count + " " + name;
    }

    public static void main(String[] args) {
        Counter heads = new Counter("heads");
        Counter tails = new Counter("tails");

        heads.increment();
        heads.increment();
        tails.increment();

        System.out.println(heads + " " + tails);
        System.out.println(heads.tally() + tails.tally());
    }
}
