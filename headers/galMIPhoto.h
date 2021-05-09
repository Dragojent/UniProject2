#ifndef GALMIPHOTO_H
#define GALMIPHOTO_H

#include <menuItem.h>

namespace gal
{
    class MIPhoto : public MenuItem<photo>
    {
        public:
            typedef int (*func)(photo&);

            MIPhoto();
            MIPhoto(std::string name, func action, photo *item);

            int action();

        private:
            photo* m_item;
            func m_action;
    };

    MIPhoto::MIPhoto() :
        m_action(nullptr), m_item(nullptr) {}

    MIPhoto::MIPhoto(std::string name, func action, photo *item) :
        m_action(action), m_item(item) {}

    int MIPhoto::action()
    { return m_action(*m_item); }

} 

#endif //GALMIPHOTO_H