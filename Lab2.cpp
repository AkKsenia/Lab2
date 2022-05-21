#include "library.h"
#include "DynamicArray.cpp"
#include "LinkedList.cpp"
#include "Sequence.h"


template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* Array;
    int size;
public:
    ArraySequence(T* items, int count) : Array(new DynamicArray<T>(items, count)), size(0) {};
    ArraySequence() : Array(new DynamicArray<T>(size)) {};
    ArraySequence(const LinkedList<T>& old_version) : Array(new DynamicArray<T>(old_version)), size(0) {};
    ArraySequence(LinkedList<T>&& old_version) : Array(new DynamicArray<T>(old_version)), size(0) {};
    virtual const T& GetFirst() override {
        if (this->Array->GetSize() == 0)
            throw "IndexOutOfRange";
        return this->Array->Get(0);
    }
    virtual const T& GetLast() override {
        if (this->Array->GetSize() == 0)
            throw "IndexOutOfRange";
        int last = this->Array->GetSize();
        return this->Array->Get(last - 1);
    }
    virtual const T& Get(int index) override {
        if ((index < 0) || (index >= this->Array->GetSize()))
            throw "IndexOutOfRange";
        return this->Array->Get(index);
    }
    virtual Sequence<T>* GetSubsequence(int startindex, int endindex) override {
        if ((startindex < 0) || (startindex >= this->Array->GetSize()) || (endindex < 0) || (endindex >= this->Array->GetSize()))
            throw "IndexOutOfRange";
        T* items = new T[endindex - startindex + 1];
        int count = startindex;
        for (int i = 0; i < (endindex - startindex + 1); i++) {
            items[i] = this->Array->Get(count);
            ++count;
        }
        ArraySequence<T> Arr(items, endindex - startindex + 1);
        Sequence<T>* seq = &Arr;
        delete[] items;
        return seq;
    }
    virtual int GetLength() override {
        return this->Array->GetSize();
    }
    virtual void Append(const T& item) override {
        int arr_size = this->Array->GetSize();
        T* arr = new T[arr_size + 1];
        for (int i = 0; i < arr_size; i++) {
            arr[i] = this->Array->Get(i);
        }
        arr[arr_size] = item;
        Array = new DynamicArray<T>(arr, arr_size + 1);
        ++size;
        delete[] arr;
    }
    virtual void Prepend(const T& item) override {
        int arr_size = this->Array->GetSize();
        T* arr = new T[arr_size * 2];
        for (int i = 0; i < arr_size; i++) {
            arr[i] = this->Array->Get(i);
        }
        this->Array->Resize(arr_size + 1);
        for (int i = arr_size; i >= 1; i--) {
            this->Array->Set(i, arr[i - 1]);
        }
        this->Array->Set(0, item);
        ++size;
        delete[] arr;
    }
    virtual void InsertAt(const T& item, int index) override {
        int arr_size = this->Array->GetSize();
        T* arr = new T[arr_size * 2];
        for (int i = 0; i < arr_size; i++) {
            arr[i] = this->Array->Get(i);
        }
        this->Array->Resize(arr_size + 1);
        for (int i = arr_size; i >= index + 1; i--) {
            this->Array->Set(i, arr[i - 1]);
        }
        this->Array->Set(index, item);
        ++size;
        delete[] arr;
    }
    Sequence<T>* Concat(const ArraySequence<T>& list) {
        int k = this->Array->GetSize();
        int new_size = list.Array->GetSize();
        T* arr = new T[k + new_size];
        for (int i = 0; i < k; i++) {
            arr[i] = this->Array->Get(i);
        }
        int p = 0;
        for (int i = k; i < k + new_size; i++) {
            arr[i] = list.Array->Get(p);
            ++p;
        }
        ArraySequence<T> a_arr(arr, k + new_size);
        Sequence<T>* aa_arr = &a_arr;
        delete[] arr;
        return aa_arr;
    }
};

template <class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T>* List;
public:
    LinkedListSequence(T* items, int count) : List(new LinkedList<T>(items, count)) {};
    LinkedListSequence() : List(new LinkedList<T>) {};
    LinkedListSequence(const LinkedList<T>& old_version) : List(new LinkedList<T>(old_version)) {};
    LinkedListSequence(LinkedList<T>&& old_version) : List(new LinkedList<T>(old_version)) {};
    virtual const T& GetFirst() override {
        return this->List->GetFirst();
    }
    virtual const T& GetLast() override {
        return this->List->GetLast();
    }
    virtual const T& Get(int index) override {
        return this->List->Get(index);
    }
    virtual Sequence<T>* GetSubsequence(int startindex, int endindex) override {
        T* items = new T[endindex - startindex + 1];
        int count = startindex;
        for (int i = 0; i < (endindex - startindex + 1); i++) {
            items[i] = this->List->Get(count);
            ++count;
        }
        LinkedListSequence<T> list(items, endindex - startindex + 1);
        Sequence<T>* seq = &list;
        delete[] items;
        return seq;
    }
    virtual int GetLength() override {
        return this->List->GetLength();
    }
    virtual void Append(const T& item) override {
        this->List->Append(item);
    }
    virtual void Prepend(const T& item) override {
        this->List->Prepend(item);
    }
    virtual void InsertAt(const T& item, int index) override {
        this->List->InsertAt(item, index);
    }
    Sequence<T>* Concat(const LinkedList<T>& list) {
        LinkedList<T>* list1 = this->List->Concat(list);
        LinkedListSequence<T> l_list(*list1);
        Sequence<T>* ll_list = &l_list;
        return ll_list;
    }
};

int main() {
    return 0;
}
