#include <iostream>

using namespace std;


struct Node {
    int data;
    Node *next;
};

typedef struct Node* node;

node getNode(int x) {
    node tmp = new Node ();
    tmp -> data = x;
    tmp -> next = NULL;
    return tmp;
}

bool empty (node a) {
    return a == nullptr;
}

int size (node a) {
    int cnt = 0;
    while(a!= NULL) {
        ++cnt;
        a = a->next;
    }
    return cnt;
}

void insertFirst (node &a, int x) {
    node tmp = getNode (x);
    
    if(a == NULL) {
        a = tmp;
    } else {
        tmp -> next = a;
        a = tmp;
    }
}

void insertLast (node &a, int x) {
    node tmp = getNode (x);
    if(a == NULL) {
        a = tmp;
    } else {
        node p = a;
        while (p->next != NULL) {
            p = p->next;
        }
        p ->next = tmp;
    }
}

void insertMiddle (node &a, int x, int pos) {
    int n = size (a);
    if(pos <= 0 || pos > n +1) {
        cout << "Vi tri can chen khong hop le!\n";
    }
    if (pos == 1) {
        insertFirst (a, x); return;
    }
    else if (pos == n + 1) {
        insertLast (a, x); return;
    }
    node p = a;
    for (int i = 1; i < pos + 1; i++) {
        p = p ->next;
    }
    node tmp = getNode(x);
    tmp -> next = p ->next;
    p->next = tmp;
}
void deleteFirst (node &a) {
    if (a == nullptr) return;
    a = a ->next;
}

void deleteLast (node &a) {
    node before = NULL, after = a;
    while (after -> next != NULL) {
        before = after;
        after = after -> next;
    }
    if (before == NULL) {
        a = NULL;
    } else {
        before -> next = NULL;
    }
}

void deleteMiddle (node &a, int pos) {
    if (pos <= 0 || pos > size(a)) return;
    node before = NULL, after = a;
    for (int i = 1; i < pos; i++) {
        before = after;
        after = after->next;
    }
    if(before == NULL) {
        a = a->next;
    } else {
        before -> next = after -> next;
    }
}

void show(node &a) {
    cout << "--------------------------------\n";
    while(a != NULL) {
        cout << a ->data << " ";
        a = a->next;
    }
    cout << "--------------------------------\n";
}

int main() {
    node head = NULL;
    while (1) {
        cout << "1. Chen phan tu vao dau danh sach\n";
        cout << "2. Chen phan tu vao cuoi danh sach\n";
        cout << "3. Chen phan tu vao giua danh sach\n";
        cout << "4. Xoa phan tu o dau\n";
        cout << "5. Xoa phan tu o cuoi\n";
        cout << "6. Xoa phan tu o giua\n";
        cout << "7. Duyet danh sach lien ket\n";
        cout << "----------------------------------------------------------------\n";
        cout << "Nhap lua chon:";
        int sl; cin >> sl;
        switch (sl)
        {
        case 1:
            int q; cout << "Nhap gia tri can chen"; cin >> q;
            insertFirst (head, q);
            break;
        case 2: 
            int w; cout << "Nhap gia tri can chen"; cin >> w;
            insertLast (head, w);
            break;
        case 3: 
            int t; cout << "Nhap gia tri can chen"; cin >> t;
            int pos; cout << "Nhap vi tri can chen"; cin >> pos;
            insertMiddle(head, t , pos);
            break;
        case 4: 
            deleteFirst(head);
            break;
        case 5:
            deleteLast(head);
            break;
        case 6:
            int y; cout << "Nhap vi tri can xoa"; cin >> y;
            deleteMiddle(head, y);
            break;
        case 7:
            show(head);
            break;
        }
    }
}