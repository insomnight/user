public class Counter {

    private String id;
    private int data;

    /**
     * 创建一个名为id的计数器
     * @param id 计数的名
     */
    public Counter(String id) {
        this.id = id;
        this.data = 0;
    }

    /**
     * 将计数器的值加一
     */
    public void increment(){
        this.data++;
    }

    public int tally(){
        return this.data;
    }

    @Override
    public String toString() {
        return id + ": " +data;
    }
}
