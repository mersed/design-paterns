/**
 * Explanation:
 * Comparing with the bad_example, we can see bellow that we have our interfaces segregated.
 * This means that if we want to implement printer, we can implement only what we need.
 * If we want to implement machine will all 3 functionalities, we can simply implement all 3
 * interfaces.
 */
#include <iostream>

struct Document;

struct IPrinter
{
    virtual void print(Document& doc) = 0;
};

struct IScanner
{
    virtual void scan(Document& doc) = 0;
};

struct IFax
{
    virtual void fax(Document& doc) = 0;
};

struct Printer : IPrinter
{
    void print(Document &doc) override {
        // this function implementation is not ok, because we dont know what to place here
    }
};

struct IMachine : IPrinter, IScanner, IFax
{
    void print(Document &doc) override {

    }

    void scan(Document &doc) override {

    }

    void fax(Document &doc) override {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
