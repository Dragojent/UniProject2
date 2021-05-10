#include <galUser.h>
#include <time.h>

using namespace gal;

int IDIncrement = 0;

User::User() :
    m_name("N/A"), m_password("1234"), m_login("1234"), m_aL(AccessLevel::user), m_ID(time(0) + IDIncrement++) {}

User::User(std::string name, std::string password, std::string login, AccessLevel aL) :
    m_name(name), m_password(password), m_login(login), m_aL(aL), m_ID(time(0) + IDIncrement++) {}

User::User(User& user) :
    m_name(user.name()), m_password(user.password()), m_login(user.login()), m_aL(user.accessLevel()), m_ID(user.ID()) {}

std::string User::name() const
{ return m_name; }

User::AccessLevel User::accessLevel() const
{ return m_aL; }

User::ID_type User::ID() const
{ return m_ID; }

std::string User::password() const
{ return m_password; }

std::string User::login() const
{ return m_login; }

User& User::operator=(const User& user)
{
    m_name = user.name();
    m_login = user.login();
    m_aL = user.accessLevel();
    m_password = user.password();
    m_ID = user.ID();

    return *this;
}