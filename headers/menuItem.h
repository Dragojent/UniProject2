#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <galMenu.h>

namespace gal
{
    template<class T>
    class MenuItem
    {
        public:
            typedef int (*func)(T&);
            
            MenuItem();
            MenuItem(std::string name, func action, T* item);
            MenuItem(std::string name);
            MenuItem(MenuItem& item);

            std::string name() const;
            int action();

        private:
            std::string m_name;
            func m_action; 
            T* m_item;
    };

    template<class T>
    MenuItem<T>::MenuItem() :
        m_name({}), m_action(nullptr), m_item(nullptr) {}
    
    template <class T>
    MenuItem<T>::MenuItem(std::string name, func action, T* item) :
        m_name(name), m_action(action), m_item(item) {}

    template <class T>
    MenuItem<T>::MenuItem(std::string name) :
        m_name(name), m_action(nullptr), m_item(nullptr) {}

    template <class T> 
    MenuItem<T>::MenuItem(MenuItem<T> &item) :
        m_name(item.name()), m_action(item.m_action), m_item(item.m_item) {}

    template <class T>
    std::string MenuItem<T>::name() const
    { return m_name; }

    template <class T>
    int MenuItem<T>::action()
    { return m_action(*m_item); }

}

#endif //MENUITEM_H