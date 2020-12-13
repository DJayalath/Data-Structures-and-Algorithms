package DesignPatterns;

public class Factory {
    // Factory method creates an instance of FactoryClass
    // Useful for returning a child class type determined by a parameter
    // passed into the factory method
    public static Factory createFactoryClass() {
        return new Factory();
    }
}
