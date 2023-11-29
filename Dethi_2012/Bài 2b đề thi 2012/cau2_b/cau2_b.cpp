#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;  // Phương thức thuần ảo
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();  // Gọi phương thức makeSound() của đối tượng Dog
    animal2->makeSound();  // Gọi phương thức makeSound() của đối tượng Cat

    delete animal1;
    delete animal2;

    return 0;
}