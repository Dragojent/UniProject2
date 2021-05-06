// #include <galSubMenu.h>
// #include <iostream>
// #include <typeinfo>
// #include <galPhoto.h>

// using namespace gal;

// template <class T>
// SubMenu<T>::SubMenu() :
//     m_name({}), m_items({}) {}

// template <class T>
// SubMenu<T>::SubMenu(std::string name, myArray<menuItem<T>*> items) :
//     m_name(name), m_items(items){}

// template <class T>
// SubMenu<T>::SubMenu(SubMenu<T>& menu) :
//     m_name(menu.name()), m_items(menu.items()) {}

// template <class T>
// void SubMenu<T>::operator=(position pos)
// {
//     if (pos > m_items.size())
//         throw "Selector out of bounds";
//     m_selector = pos;
// }

// template <class T>
// unsigned int SubMenu<T>::operator++(int)
// {
//     if (m_selector >= m_items.size() - 1)
//         m_selector = 0;
//     else 
//         m_selector++;
//     return m_selector;
// }

// template <class T>
// unsigned int SubMenu<T>::operator--(int)
// {
//     if (m_selector < 1)
//         m_selector = m_items.size() - 1;
//     else
//         m_selector--;
//     return m_selector;
// }

// template <class T>
// unsigned int SubMenu<T>::selected() const
// {
//     return m_selector;
// }

// template <class T>
// std::string SubMenu<T>::name() const
// {
//     return m_name;
// }

// template <class T>
// myArray<menuItem<T>*> SubMenu<T>::items() const
// {
//     return m_items;
// }

// template <class T>
// int SubMenu<T>::run()
// {
//     return m_items[m_selector]->action((m_items[m_selector]->item));
// }