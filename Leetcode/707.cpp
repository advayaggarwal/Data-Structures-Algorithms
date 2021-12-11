class Node {
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node *head, *tail;
    int size;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 or index >= size)   return -1;
        Node *temp = head;
        for (int i = 0; i < index; i++)  temp = temp->next;

        return temp->val;
    }

    void addAtHead(int val)
    {
        Node *n = new Node(val);
        size += 1;
        if (!head or !tail)
        {
            head = n;
            tail = n;
            return;
        }

        n->next = head;
        head = n;
    }

    void addAtTail(int val)
    {
        if (!tail or !head)
        {
            addAtHead(val);
            return;
        }

        size += 1;
        Node *n = new Node(val);
        tail->next = n;
        tail = n;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 or index > size) return;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        if (index == size)
        {
            addAtTail(val);
            return;
        }

        size += 1;
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)    temp = temp->next;

        Node *n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size) return;

        size -= 1;

        if (index == 0)
        {
            head = head->next;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)    temp = temp->next;

        if (index == size)
        {
            temp->next = NULL;
            tail = temp;
            return;
        }

        temp->next = temp->next->next;
    }
};
