package test;

import physics.forces.Force;

public class Main {

    public static int randomSequence(int min, int max) {
        return (int) (Math.random() * (max - min + 1) + min);
    }
    public static void main(String[] args) {
        /*
        float rope = Force.calculateForce(Force.forceType.TENSION, 10);
        float ropeAtAngle = Force.getForceAtAngle(rope, 45, Force.axisType.Y);
        System.out.println(ropeAtAngle);
        */
        System.out.println(randomSequence(1, 5));
        //System.out.println(Force.calculateForce(Force.forceType.FRICTION, 10, 0.5f));
    }
}