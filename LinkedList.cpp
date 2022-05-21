#include "library.h"
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList() { head = nullptr; }

template <class T>
LinkedList<T>::LinkedList(T* items, int count) {
    if (count > 0) {
        Node<T>* node1 = new Node<T>;
        Node<T>* node2 = new Node<T>;
        node1->data = items[0];
        if (count == 1) {
            node1->next = nullptr;
            head = node1;
        }
        else {
            node1->next = node2;
            head = node1;
            for (int i = 1; i < count - 1; ++i) {
                Node<T>* node3 = new Node<T>;
                node2->data = items[i];
                node2->next = node3;
                node2 = node2->next;
            }
            node2->data = items[count - 1];
            node2->next = nullptr;
        }
    }
    else head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& old_version) {
    int kol_vo = 0;
    Node<T>* cur_node = old_version.head;
    if (cur_node != nullptr) {
        while (cur_node->next != nullptr) {
            ++kol_vo;
            cur_node = cur_node->next;
        }
        ++kol_vo;
        Node<T>* node1 = new Node<T>;
        Node<T>* old_node = old_version.head;
        node1->data = old_node->data;
        old_node = old_node->next;
        if (kol_vo == 1) {
            node1->next = nullptr;
            head = node1;
        }
        else {
            node1->next = old_node;
            head = node1;
            node1 = node1->next;
            for (int i = 1; i < kol_vo - 1; ++i) {
                node1->data = old_node->data;
                old_node = old_node->next;
                node1->next = old_node;
                node1 = node1->next;
            }
            node1->data = old_node->data;
            node1->next = nullptr;
        }
    }
    else head = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& old_version) {
    int kol_vo = 0;
    Node<T>* cur_node = old_version.head;
    if (cur_node != nullptr) {
        while (cur_node->next != nullptr) {
            ++kol_vo;
            cur_node = cur_node->next;
        }
        ++kol_vo;
        Node<T>* node1 = new Node<T>;
        Node<T>* old_node = old_version.head;
        node1->data = old_node->data;
        old_node = old_node->next;
        if (kol_vo == 1) {
            node1->next = nullptr;
            head = node1;
        }
        else {
            node1->next = old_node;
            head = node1;
            node1 = node1->next;
            for (int i = 1; i < kol_vo - 1; ++i) {
                node1->data = old_node->data;
                old_node = old_node->next;
                node1->next = old_node;
                node1 = node1->next;
            }
            node1->data = old_node->data;
            node1->next = nullptr;
        }
    }
    else head = nullptr;
    old_version.head = nullptr;
}

template <class T>
LinkedList<T>* LinkedList<T>::Concat(const LinkedList<T>& list) {
    LinkedList<T>* concat_list = new LinkedList<T>();
    Node<T>* node1 = head;
    Node<T>* node2 = list.head;
    while (node1 != nullptr)
    {
        concat_list->Append(node1->data);
        node1 = node1->next;
    }
    while (node2 != nullptr)
    {
        concat_list->Append(node2->data);
        node2 = node2->next;
    }
    return concat_list;
}

template <class T>
LinkedList<T>* LinkedList<T>::GetSubList(int startindex, int endindex) {
    Node<T>* node = head;
    int kol_vo = 0;
    while (node != nullptr) {
        node = node->next;
        ++kol_vo;
    }
    if ((startindex < 0) || (startindex >= kol_vo) || (endindex < 0) || (endindex >= kol_vo))
        throw "IndexOutOfRange";
    LinkedList<T>* list = new LinkedList<T>();
    Node<T>* current = head;
    int k = 0;
    while (k != startindex) {
        current = current->next;
        ++k;
    }
    for (k; k <= endindex; k++) {
        list->Append(current->data);
        current = current->next;
    }
    return list;
}

template <class T>
void LinkedList<T>::Prepend(const T& item) {
    Node<T>* new_node = new Node<T>;
    new_node->data = item;
    new_node->next = head;
    head = new_node;
}

template <class T>
void LinkedList<T>::Append(const T& item) {
    Node<T>* new_node = new Node<T>;
    new_node->data = item;
    new_node->next = nullptr;
    Node<T>* current = head;
    if (current != nullptr) {
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    else
        head = new_node;
}

template <class T>
void LinkedList<T>::InsertAt(const T& item, int index) {
    Node<T>* node = head;
    int kol_vo = 0;
    while (node != nullptr) {
        node = node->next;
        ++kol_vo;
    }
    if ((index < 0) || (index > kol_vo))
        throw "IndexOutOfRange";
    Node<T>* new_node = new Node<T>;
    new_node->data = item;
    new_node->next = nullptr;
    Node<T>* current = head;
    Node<T>* current1 = nullptr;
    int k = 0;
    if (index > 0) {
        while (k != index - 1) {
            current = current->next;
            ++k;
        }
        current1 = current->next;
        current->next = new_node;
        current = current->next;
        current->next = current1;
    }
    if (index == 0) {
        new_node->next = head;
        head = new_node;
    }
}

template <class T>
int LinkedList<T>::GetLength() {
    int kol_vo = 0, flag = 0;
    Node<T>* current = head;
    if (current->next == nullptr)
        flag = 1;
    while (current->next != nullptr) {
        current = current->next;
        ++kol_vo;
    }
    if (flag == 0)
        return kol_vo + 1;
    else
        return kol_vo;
}

template <class T>
const T& LinkedList<T>::Get(int index) {
    Node<T>* current = head;
    Node<T>* current1 = head;
    int kol_vo = 0, k = 0;
    while (current != nullptr) {
        current = current->next;
        ++kol_vo;
    }
    if ((index < 0) || (index > kol_vo - 1))
        throw "IndexOutOfRange";
    while (k != index) {
        current1 = current1->next;
        ++k;
    }
    return current1->data;
}

template <class T>
const T& LinkedList<T>::GetLast() {
    Node<T>* current = head;
    if (current->next == nullptr)
        throw "IndexOutOfRange";
    while (current->next != nullptr) {
        current = current->next;
    }
    return current->data;
}

template <class T>
const T& LinkedList<T>::GetFirst() {
    Node<T>* current = head;
    if (current->next == nullptr)
        throw "IndexOutOfRange";
    return current->data;
}
