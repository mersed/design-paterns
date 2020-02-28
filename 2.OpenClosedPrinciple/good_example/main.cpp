/**
 * Explanation:
 * OpenClosedPrinciple states that your code should be open to the extension (by inheritence for
 * example), but closed for modification.
 *
 * We saw in bad_example, that we are actually modifying existing code instead of inheriting and
 * there by extending it. Lets see can we build a better filter using OpenClosedPrinciple.
 *
 * In order to implement our better filter, we will add 2 additional interfaces. Specification
 * interface and Filter interface. One interface will be used for defining specific specifications
 * we are going to use for filtering.
 *
 * And, when we are done with that, we can see that after filter implementation, implementing
 * Specifications for filtering is actually implementing interface with specific filter attributes,
 * which allows us to extend the existing code instead of changing the old one.
 *
 * One thing which is left is implementing filtering with two attributes. By size and color.
 * How we would implement something like this, using specification patern.
 * We can implement combinator as bellow called "AndSpecification".
 *
 * Just to reiterate and confirm what we already explained: "Goal of the OpenClosed principle is
 * to avoid jumping into the code which we already written". Thats all what it says. Open for
 * extension means that we can always create new specifications by extending/inheriting, but closed
 * for the modification - meaning that we will never require to go back into the filter interface
 * or specification interface. We would not need to change those.
 */
#include <iostream>
#include <vector>

using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
    string name;
    Color color;
    Size size;
};

template <typename T> struct Specification
{
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct Filter
{
    virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

template <typename T> struct AndSpecification : Specification<T>
{
    Specification<T>& first;
    Specification<T>& second;

    AndSpecification(Specification<T> &first, Specification<T> &second) : first(first), second(second) {}

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
    {
        vector<Product*> result;
        for(auto& item : items)
            if (spec.is_satisfied(item))
                result.push_back(item);
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    ColorSpecification(Color color) : color(color) {}

    bool is_satisfied(Product *item) override {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;

    SizeSpecification(Size size) : size(size) {}

    bool is_satisfied(Product *item) override {
        return item->size == size;
    }
};

int main() {
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};
    Product book{"Book", Color::green, Size::medium};

    vector<Product*> items {&apple, &tree, &house, &book};

    BetterFilter bf;
    ColorSpecification green(Color::green);
    SizeSpecification large(Size::large);

    for(auto &item : bf.filter(items, green))
        cout << item->name << " is green" << endl;

    AndSpecification<Product> green_and_large(green, large);
    for(auto &item : bf.filter(items, green_and_large))
        cout << item->name << " is green and large" << endl;

    return 0;
}
