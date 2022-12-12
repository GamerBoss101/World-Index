package physics.kinematics;

public class Velocity {

    public static float calculate(float distance, float time) {
        return distance / time;
    }

    public static float calculateInitalVelocity(float time, float acceleration, float distance) {
        return ((distance / time) - ((acceleration * time) / 2));
    }

    public static float getFinalVelocity(float time, float acceleration, float distance) {
        return calculateInitalVelocity(distance, time, acceleration) + (acceleration * time);
    }

    public static float calculateFinalVelocity(float velocity, float time, float acceleration) {
        return (acceleration * time) + velocity;
    }

}
    