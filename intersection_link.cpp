#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;

struct Node {
    int value;
    struct Node *next;
};

// 头插法
void CreateLinkList(Node *head, int n) {
    int value;
    for (int i = 0; i < n; i++) {
        Node *node = new Node;
        cin >> value;
        node->value = value;
        node->next = head->next;
        head->next = node;
    }
}

int Traverse(Node *head) {
    Node *p = head->next;
    int len = 0;
    while (p != NULL) {
        cout << p->value << " ";
        p = p->next;
        len++;
    }
    return len;
}

void Delete(Node *head, Node *p) {
    Node *t = head;
    Node *q = head->next;
    while (t != NULL) {
        if (q != p) {
            t = t->next;
            q = q->next;
        } else {
            t->next = q->next;
            delete p;
            p = NULL;
        }
    }
}

Node * ItersectionNode(Node *head1, Node *head2) {
    int len1 = Traverse(head1);
    int len2 = Traverse(head2);
    Node *p1 = head1->next;
    Node *p2 = head2->next;
    int k = abs(len1 - len2);
    cout << len1 << " " << len2 << endl;
    if (len1 == len2) {
        k = 0;
    } else if(len1 > len2) {
        while (k > 0) {
            p1 = p1->next;
            k--;
        }
    } else {
        while (k > 0) {
            p2 = p2->next;
            k--;
        }
    }
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1 == p2) {
        return p1;
    }
    return NULL;
}

bool IsCycleLisk(Node *head, Node *intersection_node) {
    unordered_map<int, bool> node_dict;
    Node *p = head->next;
    bool flag = false;
    while (p != NULL) {
        if (node_dict.find(&p) != node_dict.end()) {
            flag = true;
            intersection_node = p;
            break;
        } else {
            node_dict[&p] = true;
        }
    }
    return Node;
}

// len = n + m
// 

int main(int argc, char *argv[]) {
    Node *head1 = new Node;
    head1->value = 0;
    head1->next = NULL;
    Node *head2 = new Node;
    head2->value = 0;
    head2->next = NULL;
    int n;
    cin >> n;
    CreateLinkList(head1, n);
    Traverse(head1);
    CreateLinkList(head2, n);
    return 0;
}