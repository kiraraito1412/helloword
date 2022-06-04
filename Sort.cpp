#include <iostream>

using namespace std;


void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
// n is size of heap
// i is index of heap
void heapify(int a[], int n, int i) {
    int smallest = i; 
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[smallest] ) {
        smallest = l;
    }
    if (r < n && a[r] > a[smallest] ) {
        smallest = r;
    }

    if(smallest != i) {
        swap(a[i], a[smallest]);
        heapify(a, n, smallest);
    }
}

void heap_sort(int a[], int n) {
    // int i = n / 2 - 1;
    for (n; n > 0; n--) {
        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(a, n, i);
        }
            swap(a[0], a[n-1]);
    }
}
            // for (int i = 0; i < n; i++) {
            //     cout << a[i] << " ";
            // }
            //  cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    

    // for (j; j > 0; j--) {
    //     swap(a[0], a[j]);
    //     heapify(a, j, 0);
    //    for (int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // } 
    //     cout << endl;
    // }



int main()
{
   int a [1000];
   int n; 
   cout << "Nhap so phan tu";
   cin >> n; 
   for (int i = 0; i < n; i++) {
       cin >> a[i];
   }

   heap_sort(a, n);
   for (int i = 0; i < n; i++) {
       cout << a[i] << " ";
   }
}
