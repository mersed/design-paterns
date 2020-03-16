/**
 * Multiton is another variation of Singleton design pattern, but its not
 * directly related with the Singleton.
 *
 * Singleton just prevents you to have single instances. What Multiton does is,
 * that it sets up some key value, which you can use to optionally restrict number
 * of instances created from that specific class.
 *
 * Multiton is never implemented to be instanciated directly. You usually have a
 * get(key) method which accepts key, and based on that key we are returning
 * corresponding singleton instance.
 */
#include <iostream>
#include <map>
#include <memory>

enum class Importance
{
    primary,
    secondary,
    tertiary
};

template <typename  T, typename Key = std::string>
class Multiton
{
public:
    static std::shared_ptr<T> get(const Key& key)
    {
        const auto it = instances.find(key);
        if(it != instances.end())
        {
            return it->second;
        }

        auto instance = std::make_shared<T>();
        instances[key] = instance;
        return instance;
    }
protected:
    Multiton() = default;
    virtual ~Multiton() = default;
private:
    static std::map<Key, std::shared_ptr<T>> instances;
};

template <typename  T, typename Key>
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;

class Printer
{
public:
    Printer()
    {
        ++Printer::totalInstanceCount;
        std::cout << "A total of " << Printer::totalInstanceCount  << " instances created so far" << std::endl;
    }
private:
    static int totalInstanceCount;
};
int Printer::totalInstanceCount = 0;

int main() {
    typedef Multiton<Printer, Importance> mt;

    auto main = mt::get(Importance::primary);
    auto aux = mt::get(Importance::secondary);
    auto aux2 = mt::get(Importance::secondary);


    return 0;
}
