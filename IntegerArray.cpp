#include "IntegerArray.h"

integerArray::integerArray(int n) :
    size(n)
{
    if (n < 0)
        throw bad_length("Size should be >= 0");
    m_data = new int[n];
}

void integerArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    size = 0;
}

int& integerArray::operator[](int index)
{
    if (index < 0 || index >= size)
        throw bad_range("index < 0 or index >= size");
    return m_data[index];
}

void integerArray::reallocate(int newLength)
{
    erase();
    if (newLength <= 0)
        return;

    m_data = new int[newLength];
    size = newLength;
}

void  integerArray::resize(int newLength)
{
    if (newLength == size)
        return;

    if (newLength == 0)
    {
        erase();
        return;
    }

    if (newLength < 0)
        throw bad_length("Size should be >= 0");

    int* data = new int[newLength];

    if (size > 0)
    {
        int elementsToCopy = (newLength > size) ? size : newLength;

        for (int index = 0; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    size = newLength;
}

void integerArray::insert_before(int value, int index)
{
    if (index < 0 || index > size)
        throw bad_range("index < 0 or index > size");

    int* data = new int[size + 1];

    for (int before = 0; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;

    for (int after = index; after < size; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++size;
}

void  integerArray::remove(int index)
{
    if (index < 0 || index >= size)
        throw bad_range("index < 0 or index >= size");

    if (size == 1)
    {
        erase();
        return;
    }

    int* data = new int[size - 1];

    for (int before = 0; before < index; ++before)
        data[before] = m_data[before];

    for (int after = index + 1; after < size; ++after)
        data[after - 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --size;
}

void  integerArray::insert_at_beginning(int value)
{
    insert_before(value, 0);
}

void  integerArray::insert_at_end(int value)
{
    insert_before(value, size);
}

int  integerArray::get_size() const
{
    return size;
}

integerArray::iterator  integerArray::begin() const
{
    return iterator(m_data);
}

integerArray::iterator  integerArray::end() const
{
    return iterator(m_data + size);
}

integerArray::~integerArray()
{
    delete[] m_data;
}
