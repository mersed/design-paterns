/**
 * Explanation:
 *
 * DependencyInversionPrinciple says that:
 * a) High-level modules should not depend on low-level modules.
 *    Both should depend on abstractions
 * b) Abstraction should not depend on details.
 *    Details should not depend on abstractions.
 *
 * First question is, what we are considering under abstraction? Well generally, abstraction
 * is a interface or a base class.
 *
 * Now, lets see how we can break this principle. In examples bellow, we have
 * Relationship -> which is just enum class defining relationship possibilities
 * Person -> a person
 * Relationships -> class which holds a relationships ... This is what we call low level object,
 *                  because it behaves as a storage.
 * Research -> class which can perform search on relationships, and it represents high level module.
 *
 * As per our implementation bellow, we can see that our Research class gets Relationships object
 * injected into constructor, which means that it depends from the low level module.
 * Additionally, we are accessing to the details of Relationships object within Research class.
 *
 * So question is, what is going to happen if Relationship class changes ... someone changes lets say
 * name of the properties and similar? Or maybe, in low level module Relationships, someone decide
 * to make relations properties private? In that case, this code will be completly broken.
 *
 * The Research class should not depend nor be familiar with details/implementation of inner things
 * in the Relationship class.
 *
 * This is why DependencyInversionPrinciple exists in the first place. If properly implemented,
 * it protects you from the changes in implementation of details of low level classes.
 *
 * In good_example, you can see how we fixed this situation.
 */
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

struct Relationships // low level
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }
};

struct Research // high level
{
    Research(Relationships& relationships)
    {
        auto& relations = relationships.relations;
        for(auto&& [first, rel ,second] : relations)
        {
            if(first.name == "John" && rel == Relationship::parent)
                cout << "John has a child called " << second.name << endl;
        }
    }
};

int main() {
    Person parent{"John"};
    Person child1{"Chris"}, child2{"Matt"};

    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);

    Research _(relationships);
    return 0;
}
