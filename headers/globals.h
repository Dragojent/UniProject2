#if !defined(GALGLOBALS_H)
#define GALGLOBALS_H

#include <galUser.h>
#include <myArray.h>

using namespace gal;

static User Unauthorized{"unauthorized", "", "", User::AccessLevel::unauthorized};
static User *currentUser = &Unauthorized;

static myArray<User> UserBase{
    {"John", "admin", "John", User::AccessLevel::user},
    {"Kate", "12345", "Kate123", User::AccessLevel::user},
    {"Sam", "qwerty", "Sam_K", User::AccessLevel::admin},
    {"Admin", "123", "123", User::AccessLevel::admin},
};
#endif // GALGLOBALS_H 