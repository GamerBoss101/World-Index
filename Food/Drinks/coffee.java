package Food.Drinks;

public class coffee {
    private String user;
    private String type;
    private int suger;
    private int cream;
    public coffee(String user) {
        this.user = user;
    }
    public coffee type(String input) {
        this.type = input;
        return this;
    }
    public coffee setSugar(int amount) {
        this.suger = amount;
        return this;
    }
    public coffee setCream(int amount) {
        this.cream = amount;
        return this;
    }
    public String build() {
        return "Coffee for " + this.user + "\n" +
        "Type: " + this.type + "\n" +
        "Sugar: " + String.valueOf(this.suger) + " oz\n" +
        "Cream: " + String.valueOf(this.cream) + " oz.";
    }
}