package DesignPatterns;

import java.util.ArrayList;

// Observers of a subject are notified whenever a relevant update has been made
// Could add parameters to notify(...) to add contextual information
// Often used in MVC pattern to trigger rendering of objects when updated

public abstract class Observer {
    // Capitalised to distinguish between monitor usage of 'notify()'
    abstract void Notify();
}

abstract class Subject {

    private ArrayList<Observer> observerCollection;

    public void registerObserver(Observer observer) {
        observerCollection.add(observer);
    }

    public void unregisterObserver(Observer observer) {
        observerCollection.remove(observer);
    }

    public void notifyObservers() {
        for (Observer observer : observerCollection) {
            observer.Notify();
        }
    }

}