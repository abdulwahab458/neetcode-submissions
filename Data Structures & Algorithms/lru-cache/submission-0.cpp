

class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int cap;
    std::map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if(!mpp.contains(key)) return -1;
        Node* node = mpp[key];
        deleteNode(node);
        addNode(node);
        return node->val;
    }

    void put(int key, int value) {
    if (mpp.contains(key)) {
        Node* node = mpp[key];
        node->val = value;
        deleteNode(node);
        addNode(node);
    } else {
        if (mpp.size() == cap) {  // assuming 'cap' is the member variable
            Node* node = tail->prev;
            mpp.erase(node->key);
            deleteNode(node);
        }
        Node* node = new Node(key, value);
        addNode(node);
        mpp[key] = node;
    }
}

};