
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Array
{
private:
    long* arr;
    int size;

public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }

    Array(int n)
    {
        if (n < 0)
            n = 0;

        size = n;
        arr = size > 0 ? new long[size]() : nullptr;
    }

    Array(const Array& other)
    {
        size = other.size;
        arr = size > 0 ? new long[size] : nullptr;

        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
    }

    ~Array()
    {
        delete[] arr;
    }

    void fillDefault()
    {
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    void fillRandom()
    {
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 101;
    }

    void fillKeyboard()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter element " << i << ": ";
            cin >> arr[i];
        }
    }

    void print()
    {
        if (size == 0)
        {
            cout << "Array is empty!\n";
            return;
        }

        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void add(long value)
    {
        long* temp = new long[size + 1];

        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        temp[size] = value;

        delete[] arr;
        arr = temp;
        size++;
    }

    void removeIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index!\n";
            return;
        }

        long* temp = size > 1 ? new long[size - 1] : nullptr;

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i != index)
                temp[j++] = arr[i];
        }

        delete[] arr;
        arr = temp;
        size--;
    }

    void removeValue(long value)
    {
        int index = -1;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Element not found!\n";
            return;
        }

        removeIndex(index);
    }

    void sortAscending()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void sortDescending()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    long temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    long getMin()
    {
        if (size == 0)
        {
            cout << "Array is empty!\n";
            return 0;
        }

        long min = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (arr[i] < min)
                min = arr[i];
        }

        return min;
    }

    long getMax()
    {
        if (size == 0)
        {
            cout << "Array is empty!\n";
            return 0;
        }

        long max = arr[0];

        for (int i = 1; i < size; i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }

        return max;
    }

    double getAverage()
    {
        if (size == 0)
        {
            cout << "Array is empty!\n";
            return 0;
        }

        long sum = 0;

        for (int i = 0; i < size; i++)
            sum += arr[i];

        return static_cast<double>(sum) / size;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    Array a(5);

    a.fillRandom();

    cout << "Array: ";
    a.print();

    a.add(50);
    cout << "After adding 50: ";
    a.print();

    a.removeIndex(2);
    cout << "After removing index 2: ";
    a.print();

    a.removeValue(50);
    cout << "After removing value 50: ";
    a.print();

    a.sortAscending();
    cout << "Ascending: ";
    a.print();

    a.sortDescending();
    cout << "Descending: ";
    a.print();

    if (a.getSize() > 0)
    {
        cout << "Minimum: " << a.getMin() << endl;
        cout << "Maximum: " << a.getMax() << endl;
        cout << "Average: " << a.getAverage() << endl;
    }

    Array b(a);

    cout << "Copied array: ";
    b.print();

}
