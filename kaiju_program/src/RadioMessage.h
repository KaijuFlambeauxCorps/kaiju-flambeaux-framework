/*
 * RadioMessage.h
 *
 *  Created on: 15 Jan 2015
 *      Author: tully
 */

#ifndef RADIOMESSAGE_H_
#define RADIOMESSAGE_H_

namespace MessageType
{
    enum Enum : uint8_t
    {
        SetPattern
    };
}

// Forward-declare for inner reference
union RadioMessage;

union RadioMessage
{
    struct
    {
        MessageType::Enum messageType;
        uint8_t payload;
    };

    uint8_t raw[sizeof(MessageType::Enum) + sizeof(uint8_t)];

    static size_t Size() { return sizeof(RadioMessage); }
};

#endif /* RADIOMESSAGE_H_ */
