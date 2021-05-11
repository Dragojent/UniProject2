#ifndef POINTERITEM_H
#define POINTERITEM_H

#include <menuItem.h>

namespace gal
{
    template <class T>
    class PointerItem : public MenuItem
    {
        public:
            typedef int (*func)(T&);

            PointerItem();
            PointerItem(std::string name, func action, T *item);

            int action();
            void edit();

        private:
            T* m_item;
            func m_action;
    };

    template <class T>
    PointerItem<T>::PointerItem() :
        m_action(nullptr), m_item(nullptr) {}

    template <class T>
    PointerItem<T>::PointerItem(std::string name, func action, T *item) :
        m_action(action), m_item(item) 
    { m_name = name; }

    template <class T>
    int PointerItem<T>::action()
    { return m_action(*m_item); }

    template <class T>
    void PointerItem<T>::edit() {}

    template <> 
    void PointerItem<photo>::edit()
    {
        std::cout << m_item->name << std::endl;
        std::cout << m_item->content << std::endl;
        for (auto user : m_item->users)
            std::cout << user;
        std::cout << std::endl;
        std::cout << "Enter new photo" << std::endl;
        std::cout << "Name: ";
        std::cin >> m_item->name;
        std::cout << "Image: ";
        std::cin >> m_item->content;
    }

} 

#endif //POINTERITEM_H