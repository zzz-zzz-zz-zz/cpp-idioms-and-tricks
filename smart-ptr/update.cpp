#include "update.hpp"


Update::Update(const char *message_text)
{
    message = std::make_unique<Message>(message_text);
}

Message Update::get_message() const
{
    if (!message)
        throw EmptyFieldException("Message isn't exists!");
    return *message;
}