#pragma once
template <class T>
class DynamicArray {
private:
    int size_of_array;
    int capacity_of_array;
    T* data_of_array;
public:
    DynamicArray(T* items, int count);
    DynamicArray(int size = 1);
    DynamicArray(const DynamicArray<T>& old_version);
    DynamicArray(DynamicArray<T>&& old_version);
    const T& Get(int index);
    int GetSize();
    void Set(int index, const T& value);
    void Resize(int newSize);
    T& operator[](int index);
};
