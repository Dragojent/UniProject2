#ifndef GALSUBMENU_H
#define GALSUBMENU_H

#include <string>
#include <myArray.h>
#include <menuItem.h>
#include <galPhoto.h>

namespace gal
{
    class SubMenu
    {
        public:
            typedef unsigned int position;

            SubMenu();
            SubMenu(std::string name, myArray<menuItem<Photo>*> items);
            SubMenu(SubMenu& menu);

            void operator=(position pos);
            position operator++(int);
            position operator--(int);

            position selected() const;
            std::string name() const;
            myArray<menuItem<Photo>*> items() const;

            int run();

        private:
            std::string m_name;
            myArray<menuItem<Photo>*> m_items;
            position m_selector = 0;

    };
}

#endif //GALSUBMENU_H