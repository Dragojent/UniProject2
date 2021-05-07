#ifndef GALSUBMENU_H
#define GALSUBMENU_H

#include <string>
#include <myArray.h>
#include <menuItem.h>
#include <galPhoto.h>
#include <galUI.h>

namespace gal
{
    template <class T>
    class GalMenu
    {
        public:
            typedef unsigned int position;

            GalMenu();
            GalMenu(std::string name, myArray<MenuItem<T>*> items);
            GalMenu(GalMenu& menu);

            void operator=(position pos);
            position operator++(int);
            position operator--(int);
            MenuItem<T>* operator[](position index) const;
            template <class Y>
            friend std::istream& operator>>(std::istream &in, GalMenu<Y> &menu); 

            position selected() const;
            std::string name() const;
            myArray<MenuItem<T>*> items() const;
            unsigned int size() const;
            std::string nameOf(position index) const;

            int run();

            void swap(int a, int b);
            void remove(unsigned int a);
            void add(MenuItem<T> &item);

        private:
            std::string m_name;
            myArray<MenuItem<T>*> m_items;
            position m_selector = 0;

    };

    #include <iostream>
    #include <typeinfo>

    template <class T>
    GalMenu<T>::GalMenu() :
        m_name({}), m_items({}) {}

    template <class T>
    GalMenu<T>::GalMenu(std::string name, myArray<MenuItem<T>*> items) :
        m_name(name), m_items(items){}

    template <class T>
    GalMenu<T>::GalMenu(GalMenu<T>& menu) :
        m_name(menu.name()), m_items(menu.items()) {}

    template <class T>
    void GalMenu<T>::operator=(position pos)
    {
        if (pos > m_items.size())
            throw "Selector out of bounds";
        m_selector = pos;
    }

    template <class T>
    unsigned int GalMenu<T>::operator++(int)
    {
        if (m_selector >= m_items.size() - 1)
            m_selector = 0;
        else 
            m_selector++;
        return m_selector;
    }

    template <class T>
    unsigned int GalMenu<T>::operator--(int)
    {
        if (m_selector < 1)
            m_selector = m_items.size() - 1;
        else
            m_selector--;
        return m_selector;
    }

    template <class T>
    MenuItem<T>* GalMenu<T>::operator[](position index) const
    {
        return m_items[index];
    }

    template <class T>
    std::istream& operator>>(std::istream &in, GalMenu<T> &menu)
    {
        // std::string name;
        // in >> name;
        // static Photo* tmp = new Photo {name, "N/A", {}};
        // menuItem<T> item{name, dis, tmp};
        return in;
    }

    template <class T>
    unsigned int GalMenu<T>::selected() const
    {
        return m_selector;
    }

    template <class T>
    std::string GalMenu<T>::name() const
    {
        return m_name;
    }

    template <class T>
    myArray<MenuItem<T>*> GalMenu<T>::items() const
    {
        return m_items;
    }

    template <class T>
    unsigned int GalMenu<T>::size() const
    {
        return m_items.size();
    }

    template <class T>
    std::string GalMenu<T>::nameOf(position index) const
    {
        return m_items[index]->name();
    }

    template <class T>
    int GalMenu<T>::run()
    {
        return m_items[m_selector]->action();
    }

    template <class T>
    void GalMenu<T>::swap(int a, int b) 
    {
        MenuItem<T>* tmp = m_items[a];
        m_items[a] = m_items[b];
        m_items[b] = tmp;
    }

    template <class T>
    void GalMenu<T>::remove(unsigned int a)
    {
        m_items.erase(a);
    }

    template <class T>
    void GalMenu<T>::add(MenuItem<T> &item)
    {
        m_items.push_back(&item);
    }
}

#endif //GALSUBMENU_H