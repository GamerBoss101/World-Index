package Drinks;

public class coffee {
    public String user;
    public String type;
    public int suger;
    public int cream;
    public coffee(String user) {
        this.user = user;
    }
    public coffee type(String input) {
        this.type = input;
        return this;
    }
    public coffee setSugar(int input) {
        this.suger = input;
        return this;
    }
    public coffee setCream(int input) {
        this.cream = input;
        return this;
    }
    public String build() {
        return "Coffee for " + this.user + "\n" +
        "Type: " + this.type + "\n" +
        "Sugar: " + String.valueOf(this.suger) + " oz\n" +
        "Cream: " + String.valueOf(this.cream) + " oz.";
    }
}