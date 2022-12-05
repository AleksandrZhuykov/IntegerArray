#pragma once
#include <exception>

    class bad_range : public std::exception
{
    const char* message;
public:
    bad_range(const char* message) :
        message(message) { }

    const char* what()
    {
        return message;
    }
};

class bad_length : public std::exception
{
    const char* message;
public:
    bad_length(const char* message) :
        message(message) { }

    const char* what()
    {
        return message;
    }
};

class integerArray
{
private:
    int size;
    int* m_data;

public:
    class iterator {
    public:
        iterator(int* ptr) : ptr(ptr) {}
        iterator operator++() { ++ptr; return *this; }
        bool operator!=(const iterator& other) const { return ptr != other.ptr; }
        const int& operator*() const { return *ptr; }
    private:
        int* ptr;
    };

    integerArray() = default;
    integerArray(int n);

    int get_size() const;

    void erase();
    void remove(int index);

    void reallocate(int newLength);
    void resize(int newLength);

    void insert_before(int value, int index);

    void insert_at_beginning(int value);
    void insert_at_end(int value);

    int& operator[](int index);

    ~integerArray();

    iterator begin() const;
    iterator end() const;
};