#ifndef INC_3_FLUENTBUILDER_HTMLELEMENT_H
#define INC_3_FLUENTBUILDER_HTMLELEMENT_H

#include <string>
#include <vector>

struct HtmlBuilder;
struct HtmlElement
{
    friend class HtmlBuilder;
private:
    std::string name, text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement() {}

    HtmlElement(const std::string &name, const std::string &text) : name(name), text(text) {}

public:
    std::string str(int indent = 0) const;

    static HtmlBuilder build(std::string root_name);
};

#include "HtmlBuilder.h"
#endif //INC_3_FLUENTBUILDER_HTMLELEMENT_H
