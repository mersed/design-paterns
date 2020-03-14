/**
 * Singleton implementation example.
 *
 * It can look like that, there are no any kind of issues with this kind of implementation
 * or this kind of usage - however, we will see in next couple of projects that this
 * kind of approach is rather inflexible, and we will try to improve it.
 */
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <boost/lexical_cast.hpp>

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

int main() {
    std::string city1 = "Tokyo";
    int population1 = SingletonDatabase::get().get_population(city1);
    std::cout << city1 << " has population " << population1 << std::endl;

    std::string city2 = "Jakarta";
    int population2 = SingletonDatabase::get().get_population(city2);
    std::cout << city2 << " has population " << population2 << std::endl;

    return 0;
}
