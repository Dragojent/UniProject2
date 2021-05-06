#ifndef GALPHOTO_H
#define GALPHOTO_H

#include <string>
#include <myArray.h>

namespace gal
{
    struct Photo
    {
        typedef std::string picture;
        typedef unsigned long userID;

        std::string name;
        picture content;
        myArray<userID> users;
    };
}

#endif //GALPHOTO_H