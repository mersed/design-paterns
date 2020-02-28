/**
 * Explanation:
 * Comparing with previos example, what we will do here is something we call
 * "Separation of concerns"
 * Essentially what we are saying is that, Journal should take care of journal entries,
 * journal title and those kind of stuff, journal related. But if you want to have
 * persistence storage, you need to have separated component, which only job will be
 * handling persistence (saving to specific file or database for example)
 *
 * This is most robust way of handling these kind of stuff, because what happens as persistence
 * manager grow, we will have all persistence code in single place, which is responsible of
 * doing one thing and only one thing.
 *
 * If we decide to do a change, instead of using filestreams to the database for example as
 * we mentioned before, we would need to change code only on one place, instead of going around
 * and replacing everything.
 *
 * This is the core of "SingleResponsibilityPrinciple". Means that each class or module in the
 * program, should focus on a single class!
 *
 * Good rule of thumb, to determine does class breaks SingleResponsibilityPrinciple is to try
 * to describe the name of our class, and if class contains "AND" within the name, its breaking
 * SingleResponsibilityPrinciple.
 *
 * For example, in bad example of this patern, we could say that our class is "Handling journal
 * entries AND its saving those entries in the file". Based on the description of the class,
 * we can conclude that our class is doing two things, which obviously is breaking the law of
 * "SingleResponsibilityPrinciple"
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

struct Journal
{
    string title;
    vector<string> entries;

    Journal(const string &title) : title(title) {}

    void add_entry(const string &entry)
    {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ": " + entry);
    }
};

struct PersistenceManager
{
    static void save(const Journal &j, const string &filename)
    {
        ofstream ofs(filename);
        for(auto &e : j.entries)
            ofs << e << endl;
    }
};

int main() {
    Journal journal{"Dear diary"};
    journal.add_entry("I ate a bug!");
    journal.add_entry("I cried today :(");

    PersistenceManager pm;
    pm.save(journal, "GoodExampleEntries.txt");
    return 0;
}
