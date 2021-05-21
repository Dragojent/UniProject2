#ifndef GALSUBMENU_H
#define GALSUBMENU_H

#include <string>
#include <myArray.h>
#include <menuItem.h>
#include <galException.h>

namespace gal
{
    class GalMenu
    {
        public:
            enum MenuType{
                gallery = 0,
                album = 1,
                auth = 2,
                noActions = 3
            };
            typedef unsigned int position;

            GalMenu();
            GalMenu(std::string name, myArray<MenuItem*> items, MenuType type);
            GalMenu(GalMenu& menu);

            void operator=(position pos);
            position operator++(int);
            position operator--(int);
            MenuItem* operator[](position index) const;
            friend std::istream& operator>>(std::istream &in, GalMenu &menu); 

            position selected() const;
            std::string name() const;
            myArray<MenuItem*> items() const;
            unsigned int size() const;
            std::string nameOf(position index) const;
            MenuType type() const;

            int run();

            void swap(int a, int b);
            void remove(unsigned int a);
            void remove();
            void add(MenuItem &item);
            void addOption(MenuItem &item);
            void edit(unsigned int pos);
            void edit();
            void setType(MenuType type);

        private:
            std::string m_name;
            myArray<MenuItem*> m_items;
            position m_selector = 0;
            MenuType m_type;
    };

    #include <iostream>
    #include <typeinfo>

    GalMenu::GalMenu() :
        m_name({}), m_items({}) {}

    GalMenu::GalMenu(std::string name, myArray<MenuItem*> items, MenuType type) :
        m_name(name), m_items(items), m_type(type) {}

    GalMenu::GalMenu(GalMenu& menu) :
        m_name(menu.name()), m_items(menu.items()), m_type(menu.type()) {}

    void GalMenu::operator=(position pos)
    {
        if (pos > m_items.size())
            throw galException("Access error: out of bounds");
        m_selector = pos;
    }

    unsigned int GalMenu::operator++(int)
    {
        if (m_selector >= m_items.size() - 1)
            m_selector = 0;
        else 
            m_selector++;
        return m_selector;
    }

    unsigned int GalMenu::operator--(int)
    {
        if (m_selector < 1)
            m_selector = m_items.size() - 1;
        else
            m_selector--;
        return m_selector;
    }

    MenuItem* GalMenu::operator[](position index) const
    { return m_items[index]; }

    std::istream& operator>>(std::istream &in, GalMenu &menu)
    { return in; }

    unsigned int GalMenu::selected() const
    { return m_selector; }

    std::string GalMenu::name() const
    { return m_name; }

    myArray<MenuItem*> GalMenu::items() const
    { return m_items; }

    unsigned int GalMenu::size() const
    { return m_items.size(); }

    std::string GalMenu::nameOf(position index) const
    { return m_items[index]->name(); }

    GalMenu::MenuType GalMenu::type() const
    { return m_type; }

    int GalMenu::run()
    { return m_items[m_selector]->action(); }

    void GalMenu::swap(int a, int b) 
    {
        MenuItem* tmp = m_items[a];
        m_items[a] = m_items[b];
        m_items[b] = tmp;
    }

    void GalMenu::remove(unsigned int a)
    { m_items.erase(a); }

    void GalMenu::remove()
    { m_items.erase(m_selector); }

    void GalMenu::add(MenuItem &item)
    { m_items.push_back(&item); }

    void GalMenu::addOption(MenuItem &item)
    { m_items.insert(&item, m_items.size() - 1); }

    void GalMenu::edit()
    { 
        std::cout << "Edit new name\n:";
        std::string name;
        std::cin >> name;
        m_name = name;
    }

    void GalMenu::edit(unsigned int pos)
    { m_items[pos]->edit(); }
    
    void GalMenu::setType(MenuType type)
    { m_type = type; }
}

#endif //GALSUBMENU_H