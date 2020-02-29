#include <iostream>
#include "HtmlElement.h"

using namespace std;

int main() {
    auto builder = HtmlElement::build("ul")
            .add_child("li", "hello")
            .add_child("li", "world");
    cout << builder.str() << endl;

    HtmlElement elem = HtmlElement::build("ul");
    return 0;
}
