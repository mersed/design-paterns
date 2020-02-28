/**
 * Explanation:
 * Lets say that we have a Journal class, which is used for storing some
 * journal entries. Initial implementation of class is ok, but lets say, after a while
 * instead of just saving these entries in memory, we want to have persistence save,
 * in lets say some kind of file.
 *
 * In order to solve this, we add a function call save within the class,
 * which creates output filestream with filename, and store our data in that specific file.
 *
 * Problem with this approach is that we have now a separate concern called "Persistence" into
 * our journal. Imagine that, in addition to the Journal, we have other objects we are workig with,
 * and we give to every single of those objects/classes functions like save, load etc ... Problem
 * with that approach is that, when we want to change persistence, we would need to change every single
 * of these classes.
 *
 * Eg. Lets say, that we decided to move the persistence from the file to the database. We would need to
 * go around and change save methods in 10, 20 or how ever many classes we are actually using within
 * our project.
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

    void save(const string &filename)
    {
        ofstream ofs(filename);
        for(auto &e : entries)
            ofs << e << endl;
    }
};

int main() {
    Journal journal{"Dear diary"};
    journal.add_entry("I ate a bug!");
    journal.add_entry("I cried today :(");

    journal.save("BadExampleEntries.txt");
    return 0;
}
