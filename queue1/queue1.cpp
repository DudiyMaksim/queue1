#include <iostream>
using namespace std;


template <typename T>
class Queue {
    int size;
    int copacity;
    T** queue;
public:
    Queue(int s) : size{ s }, copacity{ 0 }, queue{ new T * [size] } {
        for (int i = 0; i < size; i++)
        {
            queue[i] = new T[2];
        }
    }

    bool IsEmpty() {
        return copacity == 0;
    }

    bool IsFull() {
        return copacity == size;
    }

    void InsertWithPriority(T value, T priority) {
        if (IsFull())
        {
            cout << "Queue is full!";
            return;
        }
        queue[copacity][0] = value;
        queue[copacity][1] = priority;
        copacity++;
    }

    void PullHighestPriorityElement() {
        T max = queue[0][1];
        int ind = 0;
        for (int i = 1; i < copacity; i++)
        {
            if (queue[i][1] > max)
            {
                max = queue[i][1];
                ind = i;
            }
        }
        T** newQueue = new T * [size];
        for (int i = 0; i < size; i++) {
            newQueue[i] = new T[2];
        }
        int j = 0;
        for (int i = 0; i < copacity; i++) {
            if (!(i == ind)) {
                newQueue[j][0] = queue[i][0];
                newQueue[j][1] = queue[i][1];
                j++;
            }
        }
        for (int i = 0; i < size; i++) {
            delete[] queue[i];
        }
        delete[] queue;
        queue = newQueue;

        copacity--;
    }

    T Peek() {
        T max = queue[0][1];
        int ind;
        for (int i = 1; i < copacity; i++)
        {
            if (queue[i][1] > max)
            {
                max = queue[i][1];
                ind = i;
            }
        }
        return queue[ind][0];
    }

    int GetSize() {
        return size;
    }

    void Show() {
        for (int i = 0; i < copacity; i++) {
            cout << "Value: " << queue[i][0] << ", Priority: " << queue[i][1] << endl;
        }
    }
    ~Queue() {
        for (int i = 0; i < size; i++) {
            delete[] queue[i];
        }
        delete[] queue;
    }
};




int main()
{
    Queue<int> q(10);

    q.InsertWithPriority(5, 1);
    q.InsertWithPriority(10, 3);
    q.InsertWithPriority(3, 2);

    q.Show();  

    q.PullHighestPriorityElement();
    q.Show(); 

    return 0;
}
