#include "message.hpp"


Message::Message(string the_text)
{
    text = the_text;
}

string Message::get_text() const 
{ 
    return text; 
}
