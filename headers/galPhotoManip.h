#ifndef GALPHOTOMANIP_H
#define GALPHOTOMANIP_H

#include <galPhoto.h>
#include <galUI.h>

namespace gal
{
    int view(Photo &photo)
    {
        std::cout << photo.name() << "\n" << std::endl;
        std::cout << photo.picture() << "\n" << std::endl;
        std::cout << "Tagged users: ";
        for (auto user : photo.users())
            std::cout << user << ", ";
        std::cout << std::endl;
        system("pause");
        return 0;
    }
}

#endif // GALPHOTOMANIP_H
