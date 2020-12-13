package DesignPatterns;

// Ensures a class only has one instance
public class Singleton {
    private static Singleton _instance = null;

    private Singleton() {}

    public static Singleton getInstance() {
        if (_instance == null) {
            _instance = new Singleton();
        }
        return _instance;
    }
}