#ifndef TAARRAY_H
#define TAARRAY_H
#include "defs.h"
#include "TextArea.h"

class TAArray{
public:
    TAArray();

    bool add(TextArea*);
    bool add(TextArea*, int);

    TextArea* get(int) const;
    TextArea* get(string) const;
    TextArea* remove(int);
    TextArea* remove(string);
    int getSize() const;

private:
    TextArea** textAreas;
    int numTA;
};

#endif