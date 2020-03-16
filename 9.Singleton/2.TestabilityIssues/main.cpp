/**
 * Lets explain what is the issue with singleton?
 *
 * Lets say that we have our SingletonDatabase and we want to
 * perform some research. We create a new class SingletonRecordFinder.
 *
 * For example, lets say that we want to have possibility to calculate the total
 * population in the database. SingletonRecordFinder will have a method to do that.
 * Method for that purpose will be total_population and will accept vector of cities.
 * We will loop through the cities and invoke singleton database method to retrieve
 * population for specific city. And this is going to work just fine, no specific issues
 * with it.
 *
 * However, what is going to happen if we decide to lets say, test SingletonRecordFinder?
 * This is where all the problems shows up.
 *
 * The issue with this kind of approach, is that we cannot implement proper unit testing,
 * if we want to test SingletonRecordFinder due to the fact that SingletonRecordFinder is
 * tightly coupled with SingletonDatabase.
 *
 * Any kind of tests with setup bellow would require for us to provide exact data we have
 * within the capitals.txt (which represents our database), which means that this is not
 * unit test per say, it is integration test. Additionally, what will happen if data in
 * capitals.txt (our database) changes, test are going to fail ... etc ...
 */
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

class SingletonDatabase
{
private:
    std::map<std::string, int> capitals;

    SingletonDatabase()
    {
        std::cout << "Initializing database" << std::endl;
        std::ifstream ifs("../capitals.txt");
        std::string s, s2;
        while(getline(ifs, s))
        {
            getline(ifs, s2);
            int pop = boost::lexical_cast<int>(s2);
            capitals[s] = pop;
        }
    }
public:
    // Making sure that no one cannot replicate
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }

    int get_population(const std::string &name)
    {
        return capitals[name];
    }
};

struct SingletonRecordFinder
{
    int total_population(std::vector<std::string> cities)
    {
        int result = 0;
        for(auto &city : cities)
        {
            result += SingletonDatabase::get().get_population(city);
        }
        return result;
    }
};

TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
    SingletonRecordFinder rf;
    std::vector<std::string> cities{"Tokyo", "Jakarta"};
    int tp = rf.total_population(cities);
    EXPECT_EQ(9273000+9608000, tp);
}

int main(int ac, char* av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();

    return 0;
}
