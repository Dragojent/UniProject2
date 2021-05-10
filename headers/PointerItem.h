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

} 

#endif //POINTERITEM_H