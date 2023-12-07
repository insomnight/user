public abstract class Date {

    public abstract int month();

    public abstract int day();

    public abstract int year();

    public String toString(){
        return month() + "/" + day() +"/" +year();
    }
}
