#if !defined(GAL_EXCEPTION_H)
#define GAL_EXCEPTION_H

#include <exception>

class galException : public std::exception
{
private:
    const char* m_error;

public:
    galException(const char* error) : m_error(error) {}
    const char* what() const noexcept override { return m_error; }
};

#endif // GAL_EXCEPTION_H
