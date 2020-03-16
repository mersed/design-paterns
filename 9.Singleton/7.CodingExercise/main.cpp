#include <functional>
using namespace std;

struct SingletonTester
{
    template <typename T>
    bool is_singleton(function<T*()> factory)
    {
        T* it1 = factory();
        T* it2 = factory();
        return it1 == it2;
    }
};