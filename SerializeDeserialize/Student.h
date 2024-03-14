#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <./SerializeDeserialize.h>

class Student : public SerializeDeserialize {
public:
    Student();
    Student(const QString&, size_t, const QString&);

    QString getName() const;
    void setName(const QString&);
    size_t getAge() const;
    void setAge(size_t);
    QString getBirthday() const;
    void setBirthday(const QString&);

    QString serialize() override;
    void deserialize(const QString&) override;

private:
    QString studentName;
    size_t studentAge;
    QString studentBirthday;

};

#endif
