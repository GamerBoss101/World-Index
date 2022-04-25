package Drinks;

public class coffee {
    public String name;
    public int suger;
    public int cream;
    public coffee type(String input) {
        this.name = input;
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
    public String toString() {
        return "Coffee: " + this.name + ", Sugar: " + String.valueOf(this.suger) + " oz, Cream: " + String.valueOf(this.cream) + " oz.";
    }
}