#ifndef ABSTRACTARRAY_H
#define ABSTRACTARRAY_H

class AbstractArray
{
protected:
    int elements_number;
public:
    int getElementsNumber() const {return elements_number;}
    void setElementNumber(int kol) {elements_number = kol;}
    bool IsEmpty() const
    {
        if (!elements_number)
            return true;
        return false;
    }
};

#endif // ABSTRACTARRAY_H
