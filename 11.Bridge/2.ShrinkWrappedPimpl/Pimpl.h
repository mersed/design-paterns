#ifndef INC_2_SHRINKWRAPPEDPIMPL_PIMPL_H
#define INC_2_SHRINKWRAPPEDPIMPL_PIMPL_H

#include <memory>

template <typename T>
class pimpl
{
private:
    std::unique_ptr<T> impl;

public:
    pimpl();
    ~pimpl();
    template <typename ...Args> pimpl(Args&& ...args);

    T* operator->();
    T& operator*();
};

#endif //INC_2_SHRINKWRAPPEDPIMPL_PIMPL_H
