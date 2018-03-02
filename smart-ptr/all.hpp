#ifndef _ZZZ_ALL_HPP
#define _ZZZ_ALL_HPP


#include <iostream>
#include <optional>
#include <string>
#include <memory>
#include <exception>
using std::string;
using std::optional;
using std::nullopt;
using std::unique_ptr;
using opt_string = optional<string>;

class EmptyFieldException : public std::exception
{
public:
    EmptyFieldException(const std::string msg="No message specified!")
    {
        message = "EmptyFieldException: " + msg;
    }

    virtual ~EmptyFieldException(void) {}
    virtual const char* what() { return message.c_str(); }
protected:
    std::string message;
};

class Message;
class Update;

#include "message.hpp"
#include "update.hpp"


#endif // _ZZZ_ALL_HPP