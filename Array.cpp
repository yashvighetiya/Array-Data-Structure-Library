#include<iostream>
#include<stdbool.h>
#include<string.h>
#include<string>
#include<bits/stdc++.h>

using namespace std;

/*
  1. int
  2. float
  3. double
  4. char
  5. string

  this class is used to perform array operation
*/

class Array
{
  private :
    int dataType=-2;
    int index=-2;
    void *arr;
    int size;

  public :

  //Constructor will initialize size and type of the array

    Array(int size,string dataType)
    {
        if(size <= 0)
        {
            cout << "Error : Sufficient Size not Allocated ..." << endl;
        }
        else
        {

            if(dataType.compare("int")==0)
            {
                this->size=size;
                this->index=-1;
                this->dataType=1;
                try
                {
                    arr=(void*)malloc(size * sizeof(int));

                    if (arr == NULL)
                        throw arr;
                }
                catch(...)
                {
                    cout << "Error : Buffer OverFlow ..." << endl;
                }
            }
            else if(dataType.compare("float")==0)
            {
                this->dataType=2;
                this->size=size;
                this->index=-1;
                try
                {
                    arr=(void*)malloc(size * sizeof(float));

                    if (arr == NULL)
                        throw arr;
                }
                catch(...)
                {
                    cout << "Error : Buffer OverFlow ..." << endl;
                }
            }
            else if(dataType.compare("double")==0)
            {
                this->dataType=3;
                this->size=size;
                this->index=-1;
                try
                {
                    arr=(void*)malloc(size * sizeof(double));

                    if (arr == NULL)
                        throw arr;
                }
                catch(...)
                {
                    cout << "Error : Buffer OverFlow ..." << endl;
                }
            }
            else if(dataType.compare("char")==0)
            {
                this->dataType=4;
                this->size=size;
                this->index=-1;
                try
                {
                    arr=(void*)malloc(size * sizeof(char));

                    if (arr == NULL)
                        throw arr;
                }
                catch(...)
                {
                    cout << "Error : Buffer OverFlow ..." << endl;
                }
            }
            else if(dataType.compare("string")==0)
            {
                this->dataType=5;
                this->size=size;
                this->index=-1;
                try
                {
                    arr=(void*)malloc(size * sizeof(string));

                    if (arr == NULL)
                        throw arr;
                }
                catch(...)
                {
                    cout << "Error : Buffer OverFlow ..." << endl;
                }
            }
            else
            {
                string s = "Error : Not entered Primitive DataType ... ";
                try
                {
                    throw s;
                }
                catch(string s)
                {
                    cout << s << endl;
                }
            }
        }
    }

    bool isFull()
    {
        if (index+1 == size)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if( index == -2)
            return true;
        else
            return false;
    }

    bool compareArray(Array array)
    {
        if( checkArrayInitalization() == true && array.checkArrayInitalization() == true)
        {
            if(isFull() == true && array.isFull() == true)
            {
                if(dataType == array.dataType && size == array.size)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(dataType == 1)
                        {
                            if(*((int*)arr+i) == *((int*)array.arr+i))
                            {
                                continue;
                            }
                            else
                            {
                                    return false;
                            }
                        }

                        if(dataType == 2)
                        {
                            if(*((float*)arr+i) == *((float*)array.arr+i))
                            {
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }
                        if(dataType == 3)
                        {
                            if(*((double*)arr+i) == *((double*)array.arr+i))
                            {
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }

                        if(dataType == 4)
                        {
                            if(*((char*)arr+i) == *((char*)array.arr+i))
                            {
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }
                        if(dataType == 5)
                        {
                            if(*((string*)arr+i) == *((string*)array.arr+i))
                            {
                                continue;
                            }
                            else
                            {
                                return false;
                            }
                        }
                    }
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    bool mergeArray(Array array)
    {
        if( checkArrayInitalization() == true && array.checkArrayInitalization() == true)
        {
            if(isFull() == true && array.isFull() == true)
            {
                if(dataType == array.dataType)
                {
                    if(dataType == 1)
                    {
                        try
                        {
                            size=size+array.size;
                            arr = (int*)realloc(arr,(size)*sizeof(int));
                            if (arr == NULL)
                                throw arr;
                        }
                        catch(...)
                        {
                            cout << "Error : Buffer OverFlow ..." << endl;
                        }

                        for(int i=0; i<array.size; i++)
                        {
                            index++;
                            *((int*)arr+index)=*((int*)array.arr+i);
                        }
                        return true;
                    }
                    else if(dataType == 2)
                    {
                        try
                        {
                            size=size+array.size;
                            arr = (float*)realloc(arr,(size)*sizeof(float));
                            if (arr == NULL)
                                throw arr;
                        }
                        catch(...)
                        {
                            cout << "Error : Buffer OverFlow ..." << endl;
                        }

                        for(int i=0; i<array.size; i++)
                        {
                            index++;
                            *((float*)arr+index)=*((float*)array.arr+i);
                        }
                        return true;
                    }
                    else if(dataType == 3)
                    {
                        try
                        {
                            size=size+array.size;
                            arr = (double*)realloc(arr,(size)*sizeof(double));
                            if (arr == NULL)
                                throw arr;
                        }
                        catch(...)
                        {
                            cout << "Error : Buffer OverFlow ..." << endl;
                        }

                        for(int i=0; i<array.size; i++)
                        {
                            index++;
                            *((double*)arr+index)=*((double*)array.arr+i);
                        }
                        return true;
                    }
                    else if(dataType == 4)
                    {
                        try
                        {
                            size=size+array.size;
                            arr = (char*)realloc(arr,(size)*sizeof(char));
                            if (arr == NULL)
                                throw arr;
                        }
                        catch(...)
                        {
                            cout << "Error : Buffer OverFlow ..." << endl;
                        }

                        for(int i=0; i<array.size; i++)
                        {
                            index++;
                            *((char*)arr+index)=*((char*)array.arr+i);
                        }
                        return true;
                    }
                    else if(dataType == 5)
                    {
                        try
                        {
                            size=size+array.size;
                            arr = (string*)realloc(arr,(size)*sizeof(string));
                            if (arr == NULL)
                                throw arr;
                        }
                        catch(...)
                        {
                            cout << "Error : Buffer OverFlow ..." << endl;
                        }

                        for(int i=0; i<array.size; i++)
                        {
                            index++;
                            *((string*)arr+index)=*((string*)array.arr+i);
                        }
                        return true;
                    }
                }
                else
                {
                    try
                    {
                        string s = "Error : Datatype of both array does not match ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                    return false;
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
                return false;
            }
        }
        else
        {
            printArrayUninitalizedError();
            return false;
        }
        return false;
    }

    bool checkArrayInitalization()
    {
        if( index == -2 || dataType == -2)
            return false;
        else
            return true;
    }

    void printArrayUninitalizedError()
    {
        try
        {
            string s = "Error : Array Object not Initalized ... ";
            throw s;
        }
        catch(string s)
        {
            cout << s << endl;
        }
    }

    void sortArray()
    {
        if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                if(dataType == 1)
                {
                    for(int i=0 ; i < size ; i++)
                    {
                            sort((int*)arr,(int*)arr+size);
                    }
                }
                else if(dataType == 2)
                {
                    for(int i=0 ; i < size ; i++)
                    {
                            sort((float*)arr,(float*)arr+size);
                    }
                }
                else if(dataType == 3)
                {
                    for(int i=0 ; i < size ; i++)
                    {
                            sort((double*)arr,(double*)arr+size);
                    }
                }
                else if(dataType == 4)
                {
                    for(int i=0 ; i < size ; i++)
                    {
                            sort((char*)arr,(char*)arr+size);
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }
    void displayArray()
    {
        if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {

                cout << "Array Elements are : ";
                for(int i=0 ; i < size ; i++)
                {
                    if(dataType == 1)
                        cout <<  *((int*)arr+i) << " ";
                    else if(dataType == 2)
                        cout <<  *((float*)arr+i) << " ";
                    else if(dataType == 3)
                        cout <<  *((double*)arr+i) << " ";
                    else if(dataType == 4)
                        cout <<  *((char*)arr+i) << " ";
                    else if(dataType == 5)
                        cout <<  *((string*)arr+i) << " ";
                }
                cout << endl;
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    bool splitArray(int index,Array &array1,Array &array2)
    {
        if( checkArrayInitalization() == true && array1.checkArrayInitalization() == true && array2.checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(size == array1.size + array2.size && dataType == array1.dataType && dataType == array2.dataType)
                {
                    if(index < this->index)
                    {
                            array1.index=array1.size-1;
                            array2.index=array2.size-1;
                            for(int i=0; i<=index ;i++)
                            {

                                if(dataType == 1)
                                    *((int*)array1.arr+i)=*((int*)arr+i);
                                else if(dataType == 2)
                                    *((float*)array1.arr+i)=*((float*)arr+i);
                                else if(dataType == 3)
                                    *((double*)array1.arr+i)=*((double*)arr+i);
                                else if(dataType == 4)
                                    *((char*)array1.arr+i)=*((char*)arr+i);
                                else
                                    *((string*)array1.arr+i)=*((string*)arr+i);
                            }
                            for(int i=index+1,j=0; i<size ;i++,j++)
                            {
                                if(dataType == 1)
                                    *((int*)array2.arr+j)=*((int*)arr+i);
                                else if(dataType == 2)
                                    *((float*)array2.arr+j)=*((float*)arr+i);
                                else if(dataType == 3)
                                    *((double*)array2.arr+j)=*((double*)arr+i);
                                else if(dataType == 4)
                                    *((char*)array2.arr+j)=*((char*)arr+i);
                                else
                                    *((string*)array2.arr+j)=*((string*)arr+i);
                            }
                            return true;
                    }
                    else if(index == this->index)
                    {
                        try
                        {
                            string s = "Error : Array cannot be split ...";
                            throw s;
                        }
                        catch(string s)
                        {
                            cout << s << endl;
                        }
                        return false;
                    }
                    else
                    {
                        try
                        {
                            string s = "Error : Array index out of Bound ...";
                            throw s;
                        }
                        catch(string s)
                        {
                            cout << s << endl;
                        }
                        return false;
                    }
                }
                else
                {
                    try
                    {
                        string s = "Error : Array cannot be split ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                    return false;
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
                return false;
            }
        }
        else
        {
            printArrayUninitalizedError();
            return false;
        }
        return false;
    }

    int sum(int data)
    {
        if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                if(dataType == 1)
                {
                    int sum=0;

                    for(int i=0;i<size;i++)
                    {
                        sum+=*((int*)arr+i);
                    }
                    return sum;
                }
                else
                {
                    try
                    {
                        string s = "Error : Datatype does not match ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    float sum(float data)
    {
        if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                if(dataType == 2)
                {
                    float sum=0;

                    for(int i=0;i<size;i++)
                    {
                        sum+=*((float*)arr+i);
                    }
                    return sum;
                }
                else
                {
                    try
                    {
                        string s = "Error : Datatype does not match ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    double sum(double data)
    {
        if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                if(dataType == 3)
                {
                    double sum=0;

                    for(int i=0;i<size;i++)
                    {
                        sum+=*((double*)arr+i);
                    }
                    return sum;
                }
                else
                {
                    try
                    {
                        string s = "Error : Datatype does not match ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    string sum(char data)
    {
        if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                if(dataType == 4)
                {
                    string s;

                    for(int i=0;i<size;i++)
                    {
                        s+=*((char*)arr+i);
                    }
                    return s;
                }
                else
                {
                    try
                    {
                        string s = "Error : Datatype does not match ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    string sum(string data)
    {
        if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                if(dataType == 6)
                {
                    string sum;

                    for(int i=0;i<size;i++)
                    {
                        sum+=*((string*)arr+i)+" ";
                    }
                    return sum;
                }
                else
                {
                    try
                    {
                        string s = "Error : Datatype does not match ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    void printArrayElementsUninitalizedError()
    {
         try
        {
            string s = "Error : All Array Elements are not Initalized ... ";
            throw s;
        }
        catch(string s)
        {
            cout << s << endl;
        }
    }

    void setArrayElement(int data)
    {
        if( checkArrayInitalization() == false )
        {
            printArrayUninitalizedError();
        }
        else
        {
            try
            {
                if(dataType == 1)
                {
                    try
                    {
                        if(isFull()==false)
                        {
                            index++;
                            *((int*)arr+index)=data;
                        }
                        else
                        {
                            throw index;
                        }
                    }
                    catch(int x)
                    {
                        cout << "Error : Array Index out of Bound (trying to access "<< x+1 << " index) ..." << endl;
                    }
                }
                else
                {
                    string s = "Error : int Parameter not Passed to Method setArrayElement ... " ;
                    throw s;
                }
            }
            catch(string s)
            {
                cout << s << endl;
            }
        }
    }

    int searchArrayElement(int data)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 1)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((int*)arr+i) == data)
                        {
                            return i;
                        }
                    }
                    return -1;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    int searchArrayElement(float data)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 2)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((float*)arr+i) == data)
                        {
                            return i;
                        }
                    }
                    return -1;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    int searchArrayElement(double data)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 3)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((double*)arr+i) == data)
                        {
                            return i;
                        }
                    }
                    return -1;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    int searchArrayElement(char data)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 4)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((char*)arr+i) == data)
                        {
                            return i;
                        }
                    }
                    return -1;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    int searchArrayElement(string data)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 5)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((string*)arr+i) == data)
                        {
                            return i;
                        }
                    }
                    return -1;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    bool replaceByIndex(int index,int data)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 1)
                {
                    if(index < size)
                    {
                        *((int*)arr+index)=data;
                        return true;
                    }
                    else
                    {
                        try
                        {
                            string s = "Error : Array Index out Of Bound ...";
                            throw s;
                        }
                        catch(string s)
                        {
                            cout << s << endl;
                        }
                        return false;
                    }
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                        return false;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
                return false;
            }
        }
        else
        {
            printArrayUninitalizedError();
            return false;
        }
    }

    bool replaceByData(int data1,int data2)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 1)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((int*)arr+i) == data1)
                        {
                            *((int*)arr+i) = data2;
                            return true;
                        }
                    }
                    return false;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }
    bool replaceByData(float data1,float data2)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 2)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((float*)arr+i) == data1)
                        {
                            *((float*)arr+i) = data2;
                            return true;
                        }
                    }
                    return false;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    bool replaceByData(double data1,double data2)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 3)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((double*)arr+i) == data1)
                        {
                            *((double*)arr+i) = data2;
                            return true;
                        }
                    }
                    return false;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    bool replaceByData(char data1,char data2)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 4)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((char*)arr+i) == data1)
                        {
                            *((char*)arr+i) = data2;
                            return true;
                        }
                    }
                    return false;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

    bool replaceByData(string data1,string data2)
    {
         if(checkArrayInitalization() == true)
        {
            if(isFull() == true)
            {
                if(dataType == 5)
                {
                    for(int i=0 ; i<size ; i++)
                    {
                        if(*((string*)arr+i) == data1)
                        {
                            *((string*)arr+i) = data2;
                            return true;
                        }
                    }
                    return false;
                }
                else
                {
                    try
                    {
                        string s = "Error : Array dataType does not match with search value data type ...";
                        throw s;
                    }
                    catch(string s)
                    {
                        cout << s << endl;
                    }
                }
            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }

     void setArrayElement(float data)
    {
        if( checkArrayInitalization() == false )
        {
            printArrayUninitalizedError();
        }
        else
        {
            try
            {
                if(dataType == 2)
                {
                    try
                    {
                        if(isFull()==false)
                        {
                            index++;
                            *((float*)arr+index)=data;
                        }
                        else
                        {
                            throw index;
                        }
                    }
                    catch(int x)
                    {
                        cout << "Error : Array Index out of Bound (trying to access "<< x+1 << " index) ..." << endl;
                    }
                }
                else
                {
                    string s = "Error : float Parameter not Passed to Method setArrayElement ... " ;
                    throw s;
                }
            }
            catch(string s)
            {
                cout << s << endl;
            }
        }
    }

     void setArrayElement(double data)
    {
        if( checkArrayInitalization() == false )
        {
            printArrayUninitalizedError();
        }
        else
        {
            try
            {
                if(dataType == 3)
                {
                    try
                    {
                        if(isFull()==false)
                        {
                            index++;
                            *((double*)arr+index)=data;
                        }
                        else
                        {
                            throw index;
                        }
                    }
                    catch(int x)
                    {
                        cout << "Error : Array Index out of Bound (trying to access "<< x+1 << " index) ..." << endl;
                    }
                }
                else
                {
                    string s = "Error : double Parameter not Passed to Method setArrayElement ... " ;
                    throw s;
                }
            }
            catch(string s)
            {
                cout << s << endl;
            }
        }
    }
     void setArrayElement(char data)
    {
        if( checkArrayInitalization() == false )
        {
            printArrayUninitalizedError();
        }
        else
        {
            try
            {
                if(dataType == 4)
                {
                    try
                    {
                        if(isFull()==false)
                        {
                            index++;
                            *((char*)arr+index)=data;
                        }
                        else
                        {
                            throw index;
                        }
                    }
                    catch(int x)
                    {
                        cout << "Error : Array Index out of Bound (trying to access "<< x+1 << " index) ..." << endl;
                    }
                }
                else
                {
                    string s = "Error : char Parameter not Passed to Method setArrayElement ... " ;
                    throw s;
                }
            }
            catch(string s)
            {
                cout << s << endl;
            }
        }
    }

     void setArrayElement(string data)
    {
        if( checkArrayInitalization() == false )
        {
            printArrayUninitalizedError();
        }
        else
        {
            try
            {
                if(dataType == 5)
                {
                    try
                    {
                        if(isFull()==false)
                        {
                            index++;
                            *((string*)arr+index)=data;
                        }
                        else
                        {
                            throw index;
                        }
                    }
                    catch(int x)
                    {
                        cout << "Error : Array Index out of Bound (trying to access "<< x+1 << " index) ..." << endl;
                    }
                }
                else
                {
                    string s = "Error : string Parameter not Passed to Method setArrayElement ... " ;
                    throw s;
                }
            }
            catch(string s)
            {
                cout << s << endl;
            }
        }
    }

    string arrayToString()
    {
         if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                string s;
                for(int i=0 ; i < size ; i++)
                {
                    if(dataType == 1)
                        s+=to_string(*((int*)arr+i))+" ";
                    else if(dataType == 2)
                        s+=to_string(*((float*)arr+i))+" ";
                    else if(dataType == 3)
                        s+=to_string(*((double*)arr+i))+" ";
                    else if(dataType == 4)
                        s+=*((char*)arr+i);
                    else if(dataType == 5)
                        s+=*((string*)arr+i)+" ";
                }
                return s;
            }
            else
            {
                printArrayElementsUninitalizedError();
                return "";
            }
        }
        else
        {
            printArrayUninitalizedError();
            return "";
        }
    }

    void reverseArray()
    {
         if( checkArrayInitalization() == true )
        {
            if(isFull() == true)
            {
                int start=0,end=index;
                while( start < index)
                {
                    if(dataType == 1)
                    {
                        int temp = *((int*)arr+start);
                        *((int*)arr+start) = *((int*)arr+end);
                        *((int*)arr+end) = temp;
                        start++;
                        end--;
                    }
                    else if(dataType == 2)
                    {
                        float temp = *((float*)arr+start);
                        *((float*)arr+start) = *((float*)arr+end);
                        *((float*)arr+end) = temp;
                        start++;
                        end--;
                    }
                   else if(dataType == 3)
                    {
                        double temp = *((double*)arr+start);
                        *((double*)arr+start) = *((double*)arr+end);
                        *((double*)arr+end) = temp;
                        start++;
                        end--;
                    }
                    else if(dataType == 4)
                    {
                        char temp = *((char*)arr+start);
                        *((char*)arr+start) = *((char*)arr+end);
                        *((char*)arr+end) = temp;
                        start++;
                        end--;
                    }

                    else if(dataType == 5)
                    {
                         string temp = *((string*)arr+start);
                        *((string*)arr+start) = *((string*)arr+end);
                        *((string*)arr+end) = temp;
                        start++;
                        end--;
                    }
                }

            }
            else
            {
                printArrayElementsUninitalizedError();
            }
        }
        else
        {
            printArrayUninitalizedError();
        }
    }
};

