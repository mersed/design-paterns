#ifndef INC_2_SHRINKWRAPPEDPIMPL_FOO_H
#define INC_2_SHRINKWRAPPEDPIMPL_FOO_H

#include "Pimpl.h"

class Foo
{
    class impl;
    pimpl<impl> impl;
};

#endif //INC_2_SHRINKWRAPPEDPIMPL_FOO_H
