#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <stdlib.h>

template <typename X,typename Y>
void iter(X *addr, Y len, void (*f) (X &))
{
    for(int i = 0; i < len; i++)
    {
        f(addr[i]);
    }
}

template <typename X>
void incr(X &var)
{
    var++;
}

#endif