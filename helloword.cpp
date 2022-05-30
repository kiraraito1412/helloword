#include <iostream>

using namespace std;


void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int median(int a[], int l,int r) //hàm median
{
    int median=(l+r)/2;
    if(a[median]<a[l]) swap(a[l],a[median]);
    if(a[r]<a[l]) swap(a[r],a[l]);
    if(a[r]<a[median]) swap(a[r],a[median]);
    swap(a[median],a[r-1]);
    return(r-1);
}

void quick_sort(int a[], int l, int r ) {
    
    int x = a [median(a, l, r)];
    int i = l;
    int j = r;
    do {
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } while (i <=j);
    if(l < j) {
        quick_sort(a, l, j);
    }
    if(i < r) {
        quick_sort(a, i, r);
    }
}

int main()
{
    int a[1000]; int n; 
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n -1 );
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "Nam dep trai";
}
