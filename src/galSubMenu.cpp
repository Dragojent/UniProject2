#include <galSubMenu.h>
#include <iostream>
#include <typeinfo>
#include <galPhoto.h>

using namespace gal;

SubMenu::SubMenu() :
    m_name({}), m_items({}) {}

SubMenu::SubMenu(std::string name, myArray<menuItem<Photo>*> items) :
    m_name(name), m_items(items){}

SubMenu::SubMenu(SubMenu& menu) :
    m_name(menu.name()), m_items(menu.items()) {}

void SubMenu::operator=(position pos)
{
    if (pos > m_items.size())
        throw "Selector out of bounds";
    m_selector = pos;
}

SubMenu::position SubMenu::operator++(int)
{
    if (m_selector >= m_items.size() - 1)
        m_selector = 0;
    else 
        m_selector++;
    return m_selector;
}

SubMenu::position SubMenu::operator--(int)
{
    if (m_selector < 1)
        m_selector = m_items.size() - 1;
    else
        m_selector--;
    return m_selector;
}

SubMenu::position SubMenu::selected() const
{
    return m_selector;
}

std::string SubMenu::name() const
{
    return m_name;
}

myArray<menuItem<Photo>*> SubMenu::items() const
{
    return m_items;
}

int SubMenu::run()
{
    return m_items[m_selector]->action(m_items[m_selector]->item);
}