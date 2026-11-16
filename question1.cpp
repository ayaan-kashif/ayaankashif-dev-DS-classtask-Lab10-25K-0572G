#include <iostream>
#include <string>
using namespace std;

void insert(int heap[], int &size, int value)
{
    int index = size;
    heap[size] = value;
    ++size;

    while (index > 0 && heap[index] > heap[(index - 1) / 2])
    {
        int parent = (index - 1) / 2;
        int temporary = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temporary;
        index = parent;
    }
}

bool deleteMax(int heap[], int &size, int &maximum)
{
    if (size == 0)
        return false;

    maximum = heap[0];
    --size;
    heap[0] = heap[size];

    int index = 0;
    while (2 * index + 1 < size)
    {
        int child = 2 * index + 1;
        if (child + 1 < size && heap[child + 1] > heap[child])
            ++child;

        if (heap[index] >= heap[child])
            break;

        int temporary = heap[index];
        heap[index] = heap[child];
        heap[child] = temporary;
        index = child;
    }

    return true;
}

int main()
{
    const int capacity = 100;
    int heap[capacity];
    int size = 0;
    int count;

    cout << "How many numbers? ";
    cin >> count;

    if (count < 0 || count > capacity)
    {
        cout << "Enter a number from 0 to 100.\n";
        return 1;
    }

    cout << "Enter the numbers: ";
    for (int i = 0; i < count; ++i)
    {
        int value;
        cin >> value;
        insert(heap, size, value);
    }

    cout << "Max-heap: ";
    for (int i = 0; i < size; ++i)
        cout << heap[i] << ' ';
    cout << '\n';

    int maximum;
    if (deleteMax(heap, size, maximum))
        cout << "Deleted maximum: " << maximum << '\n';
    else
        cout << "Heap is empty.\n";

    return 0;
}
