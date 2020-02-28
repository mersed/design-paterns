/**
 * Explanation:
 * Question is now, how we can fix this comparing with the bad_example.
 * Now, here, very idea of inheriting square from rectangle is not a good idea.
 *
 * Yes, from perspective of the functionality, some functionality can be the same,
 * but if we want to inhert we will need to do it differently. Either by adding the
 * flag in the Rectangle class..
 *
 * Or we can use factories for constructing rectangles or squares etc ...
 *
 * For a better example take a look into: https://www.youtube.com/watch?v=Mmy1EUKC_iE
 */
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
