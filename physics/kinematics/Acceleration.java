package physics.kinematics;

public class Acceleration {
    private static double gravity = 9.8;

    public static double getGravity() {
        return gravity;
    }

    public static float calculate(float velocity, float time) {
        return velocity / time;
    }

    public static double getAcceleration(float velocity, float time, float distance) {
        return (distance - (velocity * time)) / (2*(Math.sqrt(time)));
    }
    
}
