/**
 * Explanation:
 *
 * Comparing with bad_example, the issue can be fixed through Abstraction.
 * Instead of having direct dependency of low level module, you can introduce abstraction.
 *
 * But that is only part of the problem. The second part of the problem is, really if you want
 * to find all the children of particular person, I would argue that single responsability principle
 * still puts this responsability as part of the Relationships class. So your Research class does
 * not really have to dwelve into the details of implementation.
 *
 * So, we have two ideas:
 * - moving something to the low level modules
 * - introducing an abstraction.
 *
 * The abstraction we created will be called RelationshipBrowser
 *
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

struct RelationshipBrowser
{
    virtual vector<Person> find_all_children_of(const string& name) = 0;
};

struct Relationships : RelationshipBrowser // low level
{
    vector<tuple<Person, Relationship, Person>> relations;

    void add_parent_and_child(const Person& parent, const Person& child)
    {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    vector<Person> find_all_children_of(const string &name) override {
        vector<Person> result;
        for(auto&& [first, rel ,second] : relations)
        {
            if(first.name == "John" && rel == Relationship::parent)
                result.push_back(second);
        }

        return result;
    }
};

struct Research // high level
{
    Research(RelationshipBrowser& browser)
    {
        for(auto& child : browser.find_all_children_of("John"))
            cout << "John has a child called " << child.name << endl;
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
