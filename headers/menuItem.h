#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <galSubMenu.h>

namespace gal
{
    class SubMenu;
    struct menuItem
    {
        typedef int (*func)();

        std::string name;
        func action;
    };
}

#endif //MENUITEM_H