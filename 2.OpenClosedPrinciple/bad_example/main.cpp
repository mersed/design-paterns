/**
 * Explanation:
 * Lets suppose that we are making a programm which manages a products, and our manager
 * wants to be able to filter those products. Lets suppose that each of the products has
 * certain attributes, like for example color and size.
 *
 * So for our purpose, we are going to create enum classes for attributes, our Product class
 * and our Filter class for filtering.
 *
 * Lets focus on ProductFilter class. Lets say that our manager, wants to perform filtering
 * by color. And then we create a filter method called "by_color" and we perform the implementation.
 * We implement that method, we add some products in the main function, we perform filtering and we
 * output filtered result.
 *
 * Voala, everything is working fine, and there is no any issue with this code, until we start
 * requiring additional filters. Because at this moment, we can filter only by color.
 *
 * Now, lets suppose that your manager cames back and as you to have filter by size as well. What
 * you end up doing is creating yet another filter in the ProductFilter by size. Same would happen
 * for any other filter as well (lets say we want to add one additional filter, to filter by color
 * AND size as well) etc ...
 *
 * Once again, this is workable solution and everything will
 * work just fine, however, problem is that we had to go back and edit the code which we already
 * tested. Not only that its already tested, maybe its already shipped to the client so, now we have
 * to introduce now incompatibility by adding another interface member to product filter, which is
 * not so great.
 *
 * Generally this approach does not scale good at all. For two criteria and we already have 3 functions,
 * for 3 criteria we will have 8 functions etc ... You can see where this is going. It does not
 * scale good from perspective of code, and every single time when you want to change things you
 * need to go back into old code.
 *
 * This brings us to the OpenClosedPrinciple
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

struct ProductFilter
{
    vector <Product*> by_color(vector <Product*> items, Color color)
    {
        vector<Product*> result;
        for(auto &i : items)
            if(i->color == color)
                result.push_back(i);

        return result;
    }

    vector <Product*> by_size(vector <Product*> items, Size size)
    {
        vector<Product*> result;
        for(auto &i : items)
            if(i->size == size)
                result.push_back(i);

        return result;
    }

    vector <Product*> by_size_and_color(vector <Product*> items, Size size, Color color)
    {
        vector<Product*> result;
        for(auto &i : items)
            if(i->size == size && i->color == color)
                result.push_back(i);

        return result;
    }
};

int main() {
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};
    Product book{"Book", Color::green, Size::medium};

    vector<Product*> items {&apple, &tree, &house, &book};
    ProductFilter pf;

    auto filtered = pf.by_color(items, Color::green);
    // auto filtered = pf.by_size(items, Size::small);
    // auto filtered = pf.by_size_and_color(items, Size::medium, Color::green);

    for(auto &item : filtered)
        cout << item->name << " is green" << endl;

    return 0;
}
