/*
 * Question is, can we shrink wrapp the pimpl idiom. Make some kind of general library which
 * will make easier to use pimpl.
 *
 * And answer is, actually we can.
 * In this example, we will wrap Pimpl idiom in class which we will be able to use where ever we wants.
 */
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
