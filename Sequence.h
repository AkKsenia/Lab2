#pragma once
template <class T>
class Sequence {
public:
    virtual const T& GetFirst() = 0;
    virtual const T& GetLast() = 0;
    virtual const T& Get(int index) = 0;
    virtual int GetLength() = 0;
    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startindex, int endindex) = 0;
};
