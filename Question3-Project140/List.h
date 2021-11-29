#include <string>
using namespace std;

class List
{
private:
    struct Node;
    Node* head;
    Node* tail;
    int listSize;

public:
    List();
    class Iterator;
    Iterator begin() const;
    Iterator end() const;
    int size() const;
    bool empty() const;
    void insertFront(const string&);
    void insertBack(const string&);
    void insert(const Iterator&, const string&);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator&);
    void print();
};
struct List::Node
{
    string data;
    Node* prev;
    Node* next;
};
List::List()
{
    listSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}
class List::Iterator
{
private:
    Node* curNode;
    Iterator(Node*);
public:
    string& operator*();
    bool operator==(const Iterator&) const;
    bool operator!=(const Iterator&) const;
    Iterator& operator++();
    Iterator& operator--();
    friend class List;
};
List::Iterator List::begin() const
{
    return Iterator(head->next);
}
List::Iterator List::end() const
{
    return Iterator(tail);
}
int List::size() const
{
    return listSize;
}
bool List::empty() const
{
    return (listSize == 0);
}
void List::insert(const List::Iterator& position, const string& data)
{
    Node* posNode = position.curNode;
    Node* leftNode = posNode->prev;
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = leftNode;
    newNode->next = posNode;
    posNode->prev = newNode;
    leftNode->next = newNode;
    listSize++;
}
void List::insertFront(const string& elem)
{
    insert(begin(), elem);
}
void List::insertBack(const string& elem)
{
    insert(end(), elem);
}
void List::erase(const Iterator& position)
{
    Node* posNode = position.curNode;
    Node* leftNode = posNode->prev;
    Node* rightNode = posNode->next;
    leftNode->next = rightNode;
    rightNode->prev = leftNode;
    delete posNode;
    listSize--;
}
void List::eraseFront()
{
    erase(begin());
}
void List::eraseBack()
{
    erase(--end());
}
List::Iterator::Iterator(Node* theNode)
{
    curNode = theNode;
}
string& List::Iterator::operator*()
{
    return curNode->data;
}
bool List::Iterator::operator==(const Iterator& otherIt) const
{
    return (curNode == otherIt.curNode);
}
bool List::Iterator::operator!=(const Iterator& otherIt) const
{
    return (curNode != otherIt.curNode);
}
List::Iterator& List::Iterator::operator++()
{
    curNode = curNode->next;
    return *this;
}
List::Iterator& List::Iterator::operator--()
{
    curNode = curNode->prev;
    return *this;
}
void List::print()
{
    cout << "{ ";
    for (Iterator it = begin(); it != end(); ++it)
    {
        cout << "\"" << *it << "\" ";
    }
    cout << "}";
}