#include <galUser.h>
#include <time.h>

using namespace gal;

int IDIncrement = 0;

User::User() :
    m_name("N/A"), m_aL(AccessLevel::user), m_ID(time(0) + IDIncrement++) {}

User::User(std::string name, AccessLevel aL) :
    m_name(name), m_aL(aL), m_ID(time(0) + IDIncrement++) {}

std::string User::name() const
{ return m_name; }

User::AccessLevel User::accessLevel() const
{ return m_aL; }

User::ID_type User::ID() const
{ return m_ID; }