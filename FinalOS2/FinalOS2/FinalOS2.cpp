

#include <iostream>
#include <queue>
using namespace std;

const int N = 1000;
int i, j, nopages, refString[N], frame[N], noOfFrames, k, avail, pageFault = 0, fcount[N];

void fifo() {

    cout << "Enter String Length" << endl;
    cin >> nopages;
    cout << "Enter the string" << endl;

    for (i = 0; i < nopages; i++) {
        cin >> refString[i];
    }
    cout << "Enter no of frames" << endl;
    cin >> noOfFrames;

    for (i = 0; i < noOfFrames; i++) {
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
 
   
    cout << " Enter no of pages for which you want to calculate page faults : ";
    cin >> nopages;  
    cout << "Enter the Reference String : ";
    for (i = 0; i < nopages; i++)
    {
        
        cin >> refString[i];
    }
    cout << " Enter the Number of frames : ";
    cin >> noOfFrames;
    for (i = 0; i < noOfFrames; i++) {
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
int main()
{
    char choice = ' ';

    cout << "Enter 'f' for fifo, 'l' for lfu , 'o' for optimal" << endl;
    cin >> choice;
    switch (choice) {
    case 'f': 
        fifo();
        break;
    case 'l':
        LRU();
        break;


    }


    
    
    
}


