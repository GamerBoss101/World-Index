package physics;

public class velocity implements GlobalConstants {

    public static float calculate(float distance, float time) {
        float velocity = distance / time;
        return velocity;
    }

    public static float calculateInitalVelocity(float distance, float time, float acceleration) {
        float velocity = ((distance / time) - ((acceleration * time) / 2));
        return velocity;
    }

    public static float calculateFinalVelocity(float time, float acceleration, float distance) {
        float velocity = ((distance / time) + ((acceleration * time) / 2));
        return velocity;
    }

    public static float calculateFinalVelocity(float velocity, float time, float acceleration, float distance) {
        float velocityFinale = ((distance / time) + ((acceleration * time) / 2));
        return velocityFinale;
    }

}
    