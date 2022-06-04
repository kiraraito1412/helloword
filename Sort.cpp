#include <iostream>
#include <fstream>

using namespace std;

int a [10]={};
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
    if (l < n && a[l] < a[smallest] ) {
        smallest = l;
    }
    if (r < n && a[r] < a[smallest] ) {
        smallest = r;
    }

    if(smallest != i) {
        swap(a[i], a[smallest]);
        heapify(a, n, smallest);
    }
}

void reverse(int array[], int n, int l) {
    int r = n -1;
    swap(array[l], array[r]);
    l++;
    if(l >= r) return;
    reverse(array, r, l);
}

void heap_sort(int a[], int n) {
    for (n; n > 0; n--) {
        for (int i = n/2 - 1; i >= 0; i--) {
            heapify(a, n, i);
        }
            swap(a[0], a[n-1]);
    }
}
   
int main()
{
   int n = 0; 
   int k = 0;
   ifstream infile;
   infile.open("sort.txt");
   while(!infile.eof()) {
       infile >> a[k];
       k++;
       n++;
   }
   infile.close();
   heap_sort(a, n);
   reverse(a, n, 0);
   for (int i = 0; i < n; i++) {
       cout << a[i] << " ";
   }
   k = 0;
   ofstream outfile;
   outfile.open("sorted.txt");
   while(a[k] != '\0') {
       outfile << a[k] << " ";
       k++;
   }
   outfile.close();
}