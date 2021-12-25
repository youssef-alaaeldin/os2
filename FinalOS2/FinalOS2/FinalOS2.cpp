

#include <iostream>
#include <queue>
using namespace std;

const int N = 1000;
int i, j, n, a[N], frame[N], no, k, avail, pageFault = 0;

void fifo() {

    cout << "Enter String Length" << endl;
    cin >> n;
    cout << "Enter the string" << endl;

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter no of frames" << endl;
    cin >> no;

    for (i = 0; i < no; i++) {
        frame[i] = -1;
    }

    j = 0;
   

    for (i = 0; i < n; i++) {

        avail = 0;
        for (k = 0; k < no; k++)
            if (frame[k] == a[i])
                avail = 1;

        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % no;
            pageFault++;
        }


    }
    cout << "String after : \n";
    for (k = 0; k < no; k++)
        cout << frame[k] << " ";
    cout << endl;
    cout << "Page faults = " << pageFault;
}
int main()
{
    char choice = ' ';

    cout << "Enter 'f' for fifo, 'l' for lfu , 'o' for optimal" << endl;
    cin >> choice;
    switch (choice) {
    case 'f': 
        fifo();
        break;

    }

    
    
    
}


