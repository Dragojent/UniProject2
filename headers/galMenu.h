#ifndef GALMENU_H
#define GALMENU_H

#include <string>
#include <myArray.h>
#include <galSubMenu.h>

namespace gal
{
    class Menu
    {
        public:
            typedef unsigned int position;

            Menu();
            Menu(std::string name, myArray<SubMenu*> items, myArray<std::string> itemDes);
            Menu(Menu& menu);

            void operator=(position pos);
            position operator++(int);
            position operator--(int);

            position selected() const;
            std::string name() const;
            myArray<SubMenu*> items() const;
            myArray<std::string> itemDes() const;

            int run();

        private:
            std::string m_name;
            myArray<SubMenu*> m_items;
            myArray<std::string> m_itemDes;
            position m_selector = 0;

    };
}

#endif //GALMENU_H