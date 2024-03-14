#ifndef SERIALIZEDESERIALIZE_H
#define SERIALIZEDESERIALIZE_H

#include <QString>

class SerializeDeserialize {
public:
    virtual QString serialize() = 0;
    virtual void deserialize(const QString&) = 0;
};

#endif
