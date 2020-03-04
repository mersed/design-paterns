#include <iostream>

#include <string>
// #include <ostream>
#include <vector>
// #include <sstream>

class Class
{
    std::string class_name;
    std::vector<std::pair<std::string, std::string>> fields;
    const size_t indent_size = 2;

public:
    Class() {};

    /*
    This is correct implementation. Udemy does not allow adding libraries which they did not add to excercises
    std::string str() const
    {
        std::ostringstream oss;
        std::string i(indent_size, ' ');

        oss << "class " << class_name << std::endl;
        oss << "{" << std::endl;

        for(auto& field : fields)
            oss << i << field.second << " " << field.first << ";" << std::endl;

        oss << "};" << std::endl;

        return oss.str();
    }
    */

    std::string str() const
    {
        std::string concat;
        std::string i(indent_size, ' ');

        concat += "class " + class_name + "\n";
        concat += "{\n";

        for(auto& field : fields)
            concat += i + field.second + " " + field.first + ";\n";

        concat += "};";

        return concat;
    }

    friend class CodeBuilder;
};

class CodeBuilder
{
    Class classInstance;

public:
    CodeBuilder(const std::string& class_name)
    {
        classInstance.class_name = class_name;
    }

    CodeBuilder& add_field(const std::string& name, const std::string& type)
    {
        classInstance.fields.emplace_back(std::make_pair(name, type));
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const CodeBuilder& obj)
    {
        os << obj.classInstance.str();
        return os;
    }
};

int main() {
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    std::cout << cb;
    return 0;
}
