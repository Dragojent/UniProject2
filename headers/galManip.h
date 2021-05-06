#ifndef GALMANIP_H
#define GALMANIP_H

#include <galSubMenu.h>

namespace gal
{
    template <class T>
    int sort(SubMenu<T>& menu)
    {
        return 0;
    }

    int add();

    int remove();

    int filter();
}

#endif //GALMAINP_H