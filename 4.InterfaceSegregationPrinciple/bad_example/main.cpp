/**
 * Explanation:
 * Idea of InterfaceSegregationPrinciple is to get you not to create interfaces which are too
 * large and which requires from us to implement maybe too much.
 *
 * Lets see, how we will break this principle bellow.
 * Lets say that we have a Document type
 * Lets suppose that we want to implement an interface for Scanning, Printing and Faxing.
 * You could be tempted to place all these methods in one interface, as bellow (IMachine)
 *
 * If we are making a machine which is multipurpose printer, which can scan and fax and print,
 * then absolutely its not an issue to use this interface.
 *
 * However, question can be asked, what we will do if we want to implement machine wich is
 * performing only scanning for example?
 * We will need to implement the IMachine interface, however the only usable function is scan,
 * but we still need to implement rest of the interface functions ...?
 *
 * So, question is, what we will place in print or fax function? There are different options here:
 * - some will say, lets throw an exception from this function .. and lets not do anything
 * - some will say, lets jut leave them blank, and if they are called nothing will happen.
 *
 * The problem is that, either way, we are sending the wrong message to the user who ever is
 * going to use this class. We are saying in some kind of API that we have print and fax functions
 * but they are not doing anything.
 *
 * This violates the InterfaceSegregationPrinciple. The proper solution would be to break/segregate
 * this big interface to smaller interface and use it like that, as its showned in good_example
 */
#include <iostream>

struct Document;

struct IMachine
{
    virtual void print(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
};

struct MultiFunctionPrinter : IMachine
{
    void print(Document &doc) override {
        // because this is multifunction printer this is ok
    }

    void scan(Document &doc) override {
        // because this is multifunction printer this is ok
    }

    void fax(Document &doc) override {
        // because this is multifunction printer this is ok
    }
};

struct Scanner : IMachine
{
    void print(Document &doc) override {
        // this function implementation is not ok, because we dont know what to place here
    }

    void scan(Document &doc) override {
        // this is ok
    }

    void fax(Document &doc) override {
        // this function implementation is not ok, because we dont know what to place here
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
