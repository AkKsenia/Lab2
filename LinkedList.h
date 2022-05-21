#pragma once
template <class T>
class Node {
public:
    T data;
    Node<T>* next;
};

template <class T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList(T* items, int count);
    LinkedList();
    LinkedList(const LinkedList<T>& old_version);
    LinkedList(LinkedList<T>&& old_version);
    const T& GetFirst();
    const T& GetLast();
    const T& Get(int index);
    LinkedList<T>* GetSubList(int startindex, int endindex);
    int GetLength();
    void Append(const T& item);
    void Prepend(const T& item);
    void InsertAt(const T& item, int index);
    LinkedList<T>* Concat(const LinkedList<T>& list);
};
