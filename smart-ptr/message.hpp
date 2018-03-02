#ifndef _ZZZ_MESSAGE_HPP
#define _ZZZ_MESSAGE_HPP

#include "all.hpp"


class Message
{
public:
    Message(string text);

    string get_text() const;
private:
    string text;
};


#endif // _ZZZ_MESSAGE_HPP