package test;

import physics.forces.Force;

public class Main {
    public static void main(String[] args) {
        float rope = Force.calculateForce(Force.forceType.TENSION, 10);
        float ropeAtAngle = Force.getForceAtAngle(rope, 45, Force.axisType.Y);
        System.out.println(ropeAtAngle);
    }
}