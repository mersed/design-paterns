#include "HtmlElement.h"
#include <sstream>

std::string HtmlElement::str(int indent) const {
    std::ostringstream oss;
    std::string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << std::endl;
    if(text.size() > 0)
        oss << std::string(indent_size * (indent + 1), ' ') << text << std::endl;

    for(const auto& e : elements)
        oss << e.str(indent + 1);

    oss << i << "</" << name << ">" << std::endl;
    return oss.str();
}

HtmlBuilder HtmlElement::build(std::string root_name) { return {root_name}; }