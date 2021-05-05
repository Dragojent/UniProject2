#ifndef GALSUBMENU_H
#define GALSUBMENU_H

#include <string>
#include <myArray.h>
#include <menuItem.h>

namespace gal
{
    class SubMenu
    {
        public:
            typedef unsigned int position;

            SubMenu();
            SubMenu(std::string name, myArray<menuItem*> items);
            SubMenu(SubMenu& menu);

            void operator=(position pos);
            position operator++(int);
            position operator--(int);

            position selected() const;
            std::string name() const;
            myArray<menuItem*> items() const;

            int run();
            int run(SubMenu & menu);

        private:
            std::string m_name;
            myArray<menuItem*> m_items;
            position m_selector = 0;

    };
}

#endif //GALSUBMENU_H