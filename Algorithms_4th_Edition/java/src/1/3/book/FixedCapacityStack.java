import edu.princeton.cs.algs4.StdIn;

import java.util.Iterator;

public class FixedCapacityStack<Item> implements Iterable<Item> {
    private Item[] a;
    private int N;

    public FixedCapacityStack(int cap)
    {
        a = (Item[]) new Object[cap];
    }

    public boolean isEmpty()
    {
        return N == 0;
    }

    public int size()
    {return N;}

    public void push(Item item)
    {
        if(N == a.length)
            resize(2 * a.length);
        a[N++] = item;
    }

    public Item pop()
    {
        Item item = a[--N];
        a[N] = null;
        if(N > 0 && N == a.length / 4)
            resize(a.length/2);
        return item;
    }

    private void resize(int max)
    {
        Item[] temp = (Item[]) new Object[max];
        if (N >= 0) System.arraycopy(a, 0, temp, 0, N);
        a = temp;
    }

    public static void main(String[] args) {
        FixedCapacityStack<String> s;
        s = new FixedCapacityStack<>(100);
        while(!StdIn.isEmpty())
        {
            String item = StdIn.readString();
            if(!item.equals("-"))
                s.push(item);
            else if(!s.isEmpty()) System.out.print(s.pop() + " ");
        }
        System.out.println("(" + s.size() + " left on stack)");
    }

    @Override
    public Iterator<Item> iterator() {
        return new ReverseArrayIterator();
    }

    private class ReverseArrayIterator implements Iterator<Item>
    {
        private int i = N;

        @Override
        public boolean hasNext() {
            return i > 0;
        }

        @Override
        public Item next() {
            return a[--i];
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException("不支持修改操作");
        }
    }
}
