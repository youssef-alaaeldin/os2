

#include <iostream>
#include <queue>
using namespace std;

const int N = 1000;
int i, j, nopages, refString[N], frame[N], noOfFrames, k, avail, pageFault = 0, fcount[N];

void fifo() {

    cout<<"Enter number of frames: ";
    cin>> noOfFrames;

    cout<<"Enter number of pages: ";
    cin >> nopages;

    cout << "Enter page reference string: ";

    for (i = 0; i < nopages; ++i) {
        cin>>refString[i];
    }

    for (i = 0; i < noOfFrames; ++i) {
        frame[i] = -1;
    }

    j = 0;
   

    for (i = 0; i < nopages; i++) {

        avail = 0;
        for (k = 0; k < noOfFrames; k++)
            if (frame[k] == refString[i])
                avail = 1;

        if (avail == 0) {
            frame[j] = refString[i];
            j = (j + 1) % noOfFrames;
            pageFault++;
        }


    }
    cout << "String after : \n";
    for (k = 0; k < noOfFrames; k++)
        cout << frame[k] << " ";
    cout << endl;
    cout << "Page faults = " << pageFault;
}
void LRU() {
 
   
    cout<<"Enter number of frames: ";
    cin>> noOfFrames;

    cout<<"Enter number of pages: ";
    cin >> nopages;

    cout << "Enter page reference string: ";

    for (i = 0; i < nopages; ++i) {
        cin>>refString[i];
    }

    for (i = 0; i < noOfFrames; ++i) {
        frame[i] = -1;
        fcount[i] = 0;
    }
    i = 0;
    while (i < nopages)
    {
        int j = 0, flag = 0;
        while (j < noOfFrames)
        {
            if (refString[i] == frame[j]) {  
                flag = 1;
                fcount[j] = i + 1;
            }
            j++;
        }
        j = 0;
       
        if (flag == 0)
        {
            int min = 0, k = 0;
            while (k < noOfFrames - 1)
            {
                if (fcount[min] > fcount[k + 1]) //It will calculate the page which is least recently used
                    min = k + 1;
                k++;
            }
            frame[min] = refString[i];
            fcount[min] = i + 1;  //Increasing the time
            pageFault++;           //it will count the total Page Fault
            
        
        }
        i++;
    }
    cout << "String after : \n";
    for (k = 0; k < noOfFrames; k++)
        cout << frame[k] << " ";
    cout << endl;
    cout << "Page faults = " << pageFault;

}
void optimal() {

    int  temp[10], flag1, flag2, flag3, pos, max;
   cout<<"Enter number of frames: ";
    cin>> noOfFrames;

    cout<<"Enter number of pages: ";
    cin >> nopages;

    cout << "Enter page reference string: ";

    for (i = 0; i < nopages; ++i) {
        cin>>refString[i];
    }

    for (i = 0; i < noOfFrames; ++i) {
        frame[i] = -1;
    }

    for (i = 0; i < nopages; ++i) {
        flag1 = flag2 = 0;

        for (j = 0; j < noOfFrames; ++j) {
            if (frame[j] == refString[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (j = 0; j < noOfFrames; ++j) {
                if (frame[j] == -1) {
                    pageFault++;
                    frame[j] = refString[i];
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            flag3 = 0;

            for (j = 0; j < noOfFrames; ++j) {
                temp[j] = -1;

                for (k = i + 1; k < nopages; ++k) {
                    if (frame[j] == refString[k]) {
                        temp[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < noOfFrames; ++j) {
                if (temp[j] == -1) {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }

            if (flag3 == 0) {
                max = temp[0];
                pos = 0;

                for (j = 1; j < noOfFrames; ++j) {
                    if (temp[j] > max) {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frame[pos] = refString[i];
            pageFault++;
        }



        
    }

    cout << "String after : \n";
    for (k = 0; k < noOfFrames; k++)
        cout << frame[k] << " ";
    cout << endl;
    cout << "Page faults = " << pageFault;

}
int main()
{
    char choice = ' ';

    cout << "Enter 'f' for fifo, 'l' for LRU , 'o' for optimal" << endl;
    cin >> choice;
    switch (choice) {
    case 'f': 
        fifo();
        break;
    case 'l':
        LRU();
        break;
    case 'o':
        optimal();
        break;

    }


    
    
    
}


