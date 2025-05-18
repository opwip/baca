#include "fruit.hpp"
#include "fruit.cpp"
#include <iostream>
int main() {
    FRUIT_CLASS fruit;

    // Test the growth of the fruit
    fruit.growthFruit();
    std::cout << "Fruit weight after growth: " << fruit.getWeight() << std::endl;

    // Test the fading of the fruit
    fruit.fadeFruit();
    std::cout << "Fruit weight after fading: " << fruit.getWeight() << std::endl;

    // Test the plucking of the fruit
    fruit.pluckFruit();
    std::cout << "Fruit weight after plucking: " << fruit.getWeight() << std::endl;

    return 0;
}