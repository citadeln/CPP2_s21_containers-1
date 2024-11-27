#include "s21_containers.h"

// template<typename Type>
// Type max(Type a, Type b)
// {
// 	return (a >= b ? a : b);
// }

#include <iostream>

template<typename Type>
class s21_list
{
private:
    struct Node
    {
        Type data;
        Node* next;
        
        Node(const Type& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;

public:
    // Constructor
    s21_list() : head(nullptr), tail(nullptr) {}

    // Destructor
    ~s21_list()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Copy constructor
    s21_list(const s21_list& other) : head(nullptr), tail(nullptr)
    {
        Node* current = other.head;
        while (current != nullptr)
        {
            push_back(current->data);
            current = current->next;
        }
    }

    // Copy assignment operator
    s21_list& operator=(const s21_list& other)
    {
        if (this != &other)
        {
            s21_list temp(other);
            std::swap(head, temp.head);
            std::swap(tail, temp.tail);
        }
        return *this;
    }

    // Move constructor
    s21_list(s21_list&& other) noexcept : head(other.head), tail(other.tail)
    {
        other.head = nullptr;
        other.tail = nullptr;
    }

    // Move assignment operator
    s21_list& operator=(s21_list&& other) noexcept
    {
        if (this != &other)
        {
            clear();
            head = other.head;
            tail = other.tail;
            other.head = nullptr;
            other.tail = nullptr;
        }
        return *this;
    }

    // Utility function to add a new node to the end of the list
    void push_back(const Type& value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Utility function to clear the list
    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};
