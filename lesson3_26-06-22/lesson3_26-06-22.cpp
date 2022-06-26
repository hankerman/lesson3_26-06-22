#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nexNode;
};

class MyList {
    Node* firstNode;
    Node* lastNode;
    int length;
public:
    MyList();
    int getLenght();
    void add(int value);
    void insert(int value, int position);
    void del(int position);
    int operator[] (int index);
    void shou();
};

MyList::MyList()
{
    firstNode = nullptr;
    lastNode = nullptr;
    length = 0;
}

int MyList::getLenght() {
    return length;
}

void MyList::add(int value) {
    if (length == 0) {
        firstNode = new Node();
        firstNode->value = value;
        lastNode = firstNode;
    }
    else {
        Node* temp = lastNode;
        lastNode = new Node();
        lastNode->value = value;
        temp->nexNode = lastNode;
    }
    length++;
}

void MyList::insert(int value, int position)
{

    if (position < 0 || position > length) {
        return;
    }

    Node* newNode = new Node();
    newNode->value = value;
    Node* currentNode = firstNode;
    Node* afterNode = nullptr;

    if (position == 0) {
        newNode->nexNode = firstNode;
        firstNode = newNode;
        length++;
        return;
    }
    
    if (position == length) {
        add(value);
        return;
    }

    for (int i = 0; i <= position; i++) {
        currentNode = currentNode->nexNode;
        afterNode = currentNode->nexNode;
    }
    currentNode->nexNode = newNode;
    newNode->nexNode = afterNode;
    length++;
}

void MyList::del(int position)
{
    if (position < 0 || position >= length) {
        return;
    }
    if (position == 0) {
        firstNode = firstNode->nexNode;
        length--;
        return;
    }
    
    Node* prevNode = nullptr;
    Node* currentNode = firstNode;
    Node* afterNode = nullptr;

    for (int i = 0; i < position; i++) {
        prevNode = currentNode;
        currentNode = currentNode->nexNode;
        afterNode = currentNode->nexNode;
    }
    prevNode->nexNode = afterNode;
    length--;
}

int MyList::operator[](int index)
{
    if (index < 0 || index >= length) {
        return -1;
    }

    if (index == 0) {
        return firstNode->value;
    }
    if (index == length - 1) {
        return lastNode->value;
    }
    Node* currentNode = firstNode;
    Node* afterNode = nullptr;
    for (int i = 0; i <= index; i++) {
        currentNode = currentNode->nexNode;
        afterNode = currentNode->nexNode;
    }
    return currentNode->value;
}

void MyList::shou()
{
    Node* currentNode = firstNode;
    for (int i = 0; i < length; i++) {
        cout << currentNode->value << ' ';
        currentNode = currentNode->nexNode;
        
    }
    cout << endl;
}



int main()
{
    
    MyList list = MyList();
    list.add(5);
    list.shou();
    list.add(60);
    list.add(2);
    list.add(10);
    list.add(56);
    list.add(99);
    
    list.shou();
    list.insert(100, 3);
    list.shou();
    list.del(4);
    list.shou();

}

