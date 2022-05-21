#include "library.h"
#include "DynamicArray.h"

template <class T>
T& DynamicArray<T>:: operator[](int index) {
    return data_of_array[index];
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& old_version) {
    size_of_array = old_version.size_of_array;
    capacity_of_array = old_version.capacity_of_array;
    data_of_array = old_version.data_of_array;
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& old_version) {
    size_of_array = old_version.size_of_array;
    capacity_of_array = old_version.capacity_of_array;
    data_of_array = std::move(old_version.data_of_array);
    old_version.data_of_array = nullptr;
    old_version.size_of_array = old_version.capacity_of_array = 0;
}

template <class T>
DynamicArray<T>::DynamicArray(int size) {
    size_of_array = size;
    capacity_of_array = size_of_array;
    if (size_of_array != 0)
        data_of_array = new T[size];
    else
        data_of_array = nullptr;
}

template <class T>
DynamicArray<T>::DynamicArray(T* items, int count) {
    size_of_array = count;
    capacity_of_array = size_of_array;
    if (size_of_array != 0) {
        data_of_array = new T[count];
        for (int i = 0; i < count; i++)
            data_of_array[i] = items[i];
    }
    else
        data_of_array = nullptr;
}

template <class T>
int DynamicArray<T>::GetSize() {
    return size_of_array;
}

template <class T>
const T& DynamicArray<T>::Get(int index) {
    if ((index > size_of_array - 1) || (index < 0))
        throw "IndexOutOfRange";
    return data_of_array[index];
}

template <class T>
void DynamicArray<T>::Set(int index, const T& value) {
    if ((index > size_of_array - 1) || (index < 0))
        throw "IndexOutOfRange";
    data_of_array[index] = value;
}

template <class T>
void DynamicArray<T>::Resize(int newSize) {
    if (newSize > capacity_of_array) {
        int new_capacity = max(newSize, size_of_array * 2);
        T* new_data = new T[newSize];
        for (int i = 0; i < size_of_array; ++i)
            new_data[i] = data_of_array[i];
        delete[] data_of_array;
        data_of_array = new_data;
        capacity_of_array = new_capacity;
        delete[] new_data;
    }
    size_of_array = newSize;
}
