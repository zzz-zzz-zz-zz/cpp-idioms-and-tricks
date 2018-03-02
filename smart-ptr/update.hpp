#ifndef _ZZZ_UPDATE_HPP
#define _ZZZ_UPDATE_HPP

#include "all.hpp"


class Update
{
public:
    Update() {}
    Update(const char *message_text);
    // Update(Message m);

    Message get_message() const;
private:
    unique_ptr<Message> message = nullptr;
};


#endif // _ZZZ_UPDATE_HPP