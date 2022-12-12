package physics.forces;

public class Force {
    public enum forceType {
        GRAVITY,
        NORMAL,
        TENSION,
        FRICTION
    }
    public enum axisType {
        X,
        Y
    }
    public static float calculateForce(forceType type, float mass) {
        switch (type) {
            case GRAVITY:
                return mass * 9.8f;
            case NORMAL:
                return mass * 9.8f;
            case TENSION:
                return mass * 9.8f;
            default:
                return 0;
        }
    }
    public static float calculateForce(forceType type, float mass, float mew) {
        switch (type) {
            case FRICTION:
                return calculateForce(forceType.NORMAL, mass) * mew;
            default:
                return 0;
        }
    }
    public static float getForceAtAngle(float force, float angle, axisType axis) {
        if (axis == axisType.Y) return (float) (force * Math.sin(angle));
        if (axis == axisType.X) return (float) (force * Math.cos(angle));
        return 0;
    }
}
