#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <galSubMenu.h>
#include <any>
#include <typeinfo>

namespace gal
{
    template<class T>
    struct menuItem
    {
        typedef int (*func)(T);

        std::string name;
        func action; 
        T item;
    };
}

#endif //MENUITEM_H