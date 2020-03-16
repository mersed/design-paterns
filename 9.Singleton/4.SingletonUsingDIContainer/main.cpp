/**
 * Till now, we were creating our own singleton, by:
 * - removing copy and assignment operators
 * - making constructors private
 * - making static methods for instance creation etc ... etc ...
 *
 * There is an alternative as well. We could create a singleton instance from a  regular
 * class using di container (some already existing well written third party solutions)
 * framework
 *
 * In this absolute minimal example bellow we will use boost di
 */
#include <iostream>
#include <string>
#include <memory>
#include "di.hpp"
#include <boost/lexical_cast.hpp>

struct IFoo
{
    virtual std::string name() = 0;
};

struct Foo : IFoo
{
    static int id;
    Foo() {
        ++id;
    }

    std::string name() override {
        return "foo " + boost::lexical_cast<std::string>(id);
    }
};

int Foo::id = 0;

struct Bar
{
    std::shared_ptr<IFoo> foo;
};

int main() {
    auto injector = boost::di::make_injector(
        boost::di::bind<IFoo>().to<Foo>().in(boost::di::singleton)
    );

    auto bar1 = injector.create<std::shared_ptr<Bar>>();
    auto bar2 = injector.create<std::shared_ptr<Bar>>();

    std::cout << bar1->foo->name() << " on location: " << bar1->foo.get() << std::endl;
    std::cout << bar2->foo->name() << " on location: " << bar2->foo.get() << std::endl;
    return 0;
}
