#include "Student.h"

#include <QStringList>

Student::Student()
{

}

Student::Student(const QString &name, size_t age, const QString &birthday)
    : studentName(name),
    studentAge(age),
    studentBirthday(birthday)
{
}

QString Student::getName() const
{
    return studentName;
}

void Student::setName(const QString &name)
{
    studentName = name;
}

size_t Student::getAge() const
{
    return studentAge;
}

void Student::setAge(size_t age)
{
    studentAge = age;
}

QString Student::getBirthday() const
{
    return studentBirthday;
}

void Student::setBirthday(const QString &birthday)
{
    studentBirthday = birthday;
}

QString Student::serialize()
{
    return studentName + "-" + QString::number(studentAge) + "-" + studentBirthday;
}

void Student::deserialize(const QString &serializedData)
{
    QStringList splittedData = serializedData.split("-");
    if (splittedData.size() != 3)
        throw std::runtime_error("Could not parse data");

    studentName = splittedData[0];
    studentAge = splittedData[1].toInt();
    studentBirthday = splittedData[2];
}
