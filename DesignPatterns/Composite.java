package DesignPatterns;

import java.util.ArrayList;
import java.util.Iterator;

// A tree pattern where Leaf and Composite are both nodes inheriting from Component and a Composite can hold lots of Components
// A good pattern for building complex components out of simple ones by grouping components recursively into larger ones

// Effectively, leaves are primitives, and composites are containers for the primitives.

// Example: Grouping tasks under different kinds of activities

abstract class Component {
    public abstract void operation();
}

class Leaf extends Component {

    @Override
    public void operation() {
        // Implementation goes here
    }
    
}

public class Composite extends Component {

    private ArrayList<Component> components;

    public Composite() {
        components = new ArrayList<>();
    }

    public void addComponent(Component component) {
        components.add(component);
    }

    public void removeComponent(Component component) {
        components.remove(component);
    }

    Iterator<Component> getChildren() {
        return components.iterator();
    }

    @Override
    public void operation() {
        // Implementation goes here
    }
    
}
