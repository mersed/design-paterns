/**
 * Before we look at canonnical implementation of bridge design pattern, lets check
 * Pimpl Idiom first. The reason we are going to show Pimpl Idiom is because
 * it is also a manifestation of Bridge design pattern, just slightly different one.
 *
 * Pimpl Idiom is all about hiding implementation details of the particular class by
 * sticking it into its implementation as the name suggest.
 *
 * So idea of the Pimpl Idiom is that, implementaiton details (in our example of Person class)
 * instead of to be written within the Person.cpp class, they are actually written (bridged)
 * into the separate class.
 *
 * We usually have a separate class which is defined within our class (same as in our example)
 *
 * If we check our class Person in this project, we can find the full example of the Pimpl Idiom.
 * If we check the implementation, we will see that we have an impl class within the person class
 * in order to be able to implement his. Question is, why we would want to implement things like this
 * at all. Seems more complicated and unnecessary.
 *
 * Well, there are two exact reasons:
 * 1. One advantage is that we really hiding implementation details. Who ever is using our api (class),
 * we need to give them header at least .hpp file. Now, if we had lots of private implementation details
 * and we were not doing Pimpl Idiom, we would have private section of the class, and we would have a lots
 * of secret method implementation details there (declarations in header file - or even implementations in inline
 * form)
 * 2. And second one (which is the biggest reason) is that, it allows us to change the implementation underneath
 * without changing surface API. As a result we will not introduce binary compatibility. If we start adding
 * things to our class (like more additional methods), who ever is using it, he will need to recompile it.
 * With PimplIdiom that is not necessary. We are hiding implementation details behind impl pointer, we could simply
 * recompile and ship our binary - but customer which consumes the api does not need to do that.
 *
 * Pimpl (Pointer to implementation).
 */
#include "Person.h"

int main() {

    Person john = Person{"John"};
    john.greet();

    return 0;
}
