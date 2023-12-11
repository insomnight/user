import java.util.Objects;

public class Transaction {

    private String custName;

    private SmartDate transactionDate;

    private double amount;

    public Transaction(String who,SmartDate when,double amount) {
        custName = who;
        transactionDate = new SmartDate(when.day(),when.month(),when.year());
        this.amount = amount;
    }

    public String who()
    {
        return custName;
    }

    public SmartDate when()
    {
        return transactionDate = new SmartDate(transactionDate.day(),transactionDate.month(),transactionDate.year());
    }

    public double amount()
    {
        return amount;
    }

    @Override
    public String toString() {
       return "[" + custName + ", " + transactionDate + ", "+amount+"]";
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Transaction that = (Transaction) o;
        return Double.compare(amount, that.amount) == 0 && Objects.equals(custName, that.custName) && Objects.equals(transactionDate, that.transactionDate);
    }

    @Override
    public int hashCode() {
        return Objects.hash(custName, transactionDate, amount);
    }
}
