#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <galMenu.h>

namespace gal
{
    class MenuItem
    {
        public:
            typedef int (*func)();
            
            MenuItem();
            MenuItem(std::string name, func action);
            MenuItem(std::string name);
            MenuItem(MenuItem& item);

            std::string name() const;
            virtual int action();
            virtual void edit();

        protected:
            std::string m_name;

        private:
            func m_action; 
    };

    MenuItem::MenuItem() :
        m_name({}), m_action(nullptr) {}
    
    MenuItem::MenuItem(std::string name, func action) :
        m_name(name), m_action(action) {}

    MenuItem::MenuItem(std::string name) :
        m_name(name), m_action(nullptr) {}

    MenuItem::MenuItem(MenuItem &item) :
        m_name(item.name()), m_action(item.m_action) {}

    std::string MenuItem::name() const
    { return m_name; }

    int MenuItem::action()
    { return m_action(); }

    void MenuItem::edit() {}

}

#endif //MENUITEM_H