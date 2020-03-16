/**
 * Monostate is interesting variation of Singleton design patern.
 * Idea is rather simple.
 *
 * Lets say that we want to have a class printer.
 * Monostate indicates that we will create a regular class,
 * however, all of the data within the class is going to be static.
 *
 * Which means that it does not matter how many instances you create ...
 * If you create another printer, or any other instance of printer, that
 * instance will create same static state as the rest of the instances already created
 * (due to the static keyword behaviour).
 *
 * This is really inflexible and really bizare solution which is applied in really rare
 * situations ... Inheritance will not work with this for example (you are not able to
 * inherit static attributes) ...
 */
class Printer
{
    static int id;
public:
    int get_id()
    {
        return id;
    }

    void set_id(int value)
    {
        id = value;
    }
};
int Printer::id = 0;

int main() {
    Printer p;
    int id = p.get_id();
    p.set_id(4);

    Printer p2;
    int id2 = p2.get_id();
    return 0;
}
