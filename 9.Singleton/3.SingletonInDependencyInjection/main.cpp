/**
 * So, singletons are not bad per-say ... However, they can be extremly bad
 * if they are not used properly - and if there is a tight coupling between object
 * which is using it - and between singleton.
 *
 * In example bellow, we can see how singleton instance is injected into the instace
 * which we want to test.
 * This allows us to inject the fake (dummy) singleton, which is suitable for our testing
 * and unit tests.
 *
 * Like this, we resolved the issue which we mentioned in previous example
 */
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <gtest/gtest.h>

class Database
{
public:
    virtual int get_population(const std::string&) = 0;
};

class SingletonDatabase : public Database
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

class DummyDatabase : public Database
{
    std::map<std::string, int> capitals;

public:
    DummyDatabase()
    {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gama"] = 3;
    }

private:

    int get_population(const std::string &name) override 
    {
        return capitals[name];
    }
};

class ConfigurableRecordFinder
{
    Database& db;

public:
    ConfigurableRecordFinder(Database &db) : db(db) {}

    int total_population(std::vector<std::string> cities)
    {
        int result = 0;
        for(auto &city : cities)
        {
            result += db.get_population(city);
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

TEST(RecordFinderTests, IndependentTotalPopulationTest)
{
    DummyDatabase db;
    ConfigurableRecordFinder crf{db};
    std::vector<std::string> cities{"alpha", "gama"};
    int tp = crf.total_population(cities);
    EXPECT_EQ(4, tp);
}

int main(int ac, char* av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();

    return 0;
}
