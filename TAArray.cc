#include "TAArray.h"

TAArray::TAArray(){
    textAreas = new TextArea*[MAX_COMPONENTS];
    numTA = 0;
}

bool TAArray::add(TextArea* ta){
    if(numTA >= MAX_COMPONENTS) return false;
    textAreas[numTA++] = ta;
    return true;
}

bool TAArray::add(TextArea* ta, int index){
    if(numTA == 0 && index == 0){
        add(ta);
        return true;
    }

    if(index >= 0 && index <= numTA){
        for(int i = numTA; i > index; i--){
            textAreas[i] = textAreas[i-1];
        }
        textAreas[index] = ta;
        numTA++;
        return true;
    }

    return false;
}

TextArea* TAArray::get(int index) const{
    if(index >= 0 && index < numTA){
        return textAreas[index];
    }
    return nullptr;
}

TextArea* TAArray::get(string name) const{
    for(int i = 0; i < numTA; i++){
        if(name.compare(textAreas[i]->getID()) == 0){
            return textAreas[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::remove(int index){
    if(index >= 0 && index < numTA){
        TextArea* result = textAreas[index];
        for(int i = index; i < numTA-1; i++){
            textAreas[i] = textAreas[i+1];
        }
        numTA--;
        return result;
    }
    return nullptr;
}

TextArea* TAArray::remove(string name){
    for(int i = 0; i < numTA; i++){
        if(name.compare(textAreas[i]->getID()) == 0){
            TextArea* result = textAreas[i];
            for(int j = i; j < numTA-1; j++){
                textAreas[j] = textAreas[j+1];
            }
            numTA--;
            return result;
        }
    }
    return nullptr;
}

int TAArray::getSize() const{
    return numTA;
}