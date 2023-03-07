#ifndef EXTARRAYLISTTYPE_H
#define EXTARRAYLISTTYPE_H
#include "arrayListType.h"

template <class Type>
class extArrayListType : public arrayListType<Type>
{
public:
    void removeAt(int);
    void removeAll(const Type&);
    Type min() const;
    Type max() const;
    extArrayListType<Type>(int s): arrayListType<Type>(s) {};
};
template <class Type>
void extArrayListType<Type>::removeAt(int location)
{
    if (location < 0 || location >= this->length)
        cerr << "The location of the item to be removed "
        << "is out of range" << endl;
    else
    {
        this->list[location] = this->list[this->length - 1];
        this->length--;
    }
}
template <class Type>
void extArrayListType<Type>::removeAll(const Type& removeItem)
{
    int location;

    if (this->length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        location = 0;

        while (location < this->length)
            if (this->list[location] == removeItem)
                removeAt(location);
            else
                location++;
    }
}
template <class Type>
Type extArrayListType<Type>::min() const
{
    Type smallest = this->list[0];
    for (int i = 1; i < this->length; i++){
        if (this->list[i] < smallest)
            smallest = this->list[i];
    }
    return smallest;
}
template <class Type>
Type extArrayListType<Type>::max() const
{
    Type largest = this->list[0];

    for (int i = 1; i < this->length; i++)
        if (this->list[i] > largest)
            largest = this->list[i];
    return largest;
}


#endif
