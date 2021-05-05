#include <galMenu.h>
#include <iostream>
#include <galUI.h>

using namespace gal;

Menu::Menu() :
    m_name({}), m_items({}), m_itemDes({}) {}

Menu::Menu(std::string name, myArray<SubMenu*> items, myArray<std::string> itemDes) :
    m_name(name), m_items(items), m_itemDes(itemDes) {};

Menu::Menu(Menu& menu) :
    m_name(menu.name()), m_items(menu.items()), m_itemDes(menu.itemDes()) {}

void Menu::operator=(position pos)
{
    if (pos > m_items.size())
        throw "Selector out of bounds";
    m_selector = pos;
}

Menu::position Menu::operator++(int)
{
    if (m_selector >= m_items.size() - 1)
        m_selector = 0;
    else 
        m_selector++;
    return m_selector;
}

Menu::position Menu::operator--(int)
{
    if (m_selector < 1)
        m_selector = m_items.size() - 1;
    else
        m_selector--;
    return m_selector;
}

Menu::position Menu::selected() const
{
    return m_selector;
}

std::string Menu::name() const
{
    return m_name;
}

myArray<SubMenu*> Menu::items() const
{
    return m_items;
}

myArray<std::string> Menu::itemDes() const
{
    return m_itemDes;
}

int Menu::run()
{
    // return start(m_items[m_selector]);
}