#ifndef INC_3_FLUENTBUILDER_HTMLBUILDER_H
#define INC_3_FLUENTBUILDER_HTMLBUILDER_H

#include <string>
#include "HtmlElement.h"

struct HtmlBuilder
{
    HtmlElement root;

    HtmlBuilder(std::string root_name);

    HtmlBuilder& add_child(std::string child_name, std::string child_text);

    std::string str() const;

    operator HtmlElement() const { return root; }
};

#endif //INC_3_FLUENTBUILDER_HTMLBUILDER_H
