class Animal {
    void makeSound() {
        System.out.println("The animal makes a sound");
    }
}

class Dog extends Animal {
    @Override 
    void makeSound() {
        System.out.println("The dog barks");
    }
}

class Cat extends Animal {
   @Override
    void makeSound() {
        System.out.println("The cat meows");
    }
}

public class MORRDconcept {
    public static void main(String[] args) {
        Animal myAnimal = new Animal();
        Animal myDog = new Dog();
        Animal myCat = new Cat();

        myAnimal.makeSound();
        myDog.makeSound();
        myCat.makeSound();
    }
}
