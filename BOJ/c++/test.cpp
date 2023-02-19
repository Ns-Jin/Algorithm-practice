#include <bits/stdc++.h>
using namespace std;
string myimg[128];

void qts_recursive(string curqts, int size, int x, int y){
    string qts[4];
    int brcnt=0, qtscnt=0;
    
    if (curqts.length()==1){
        for(int k=x; k<x+size; k++)
            for(int j=y; j<y+size; j++) myimg[k][j]=curqts[0];
        return;
    }
    for(int i=1; i<curqts.length()-1; i++){
        if(brcnt==0){
            qtscnt+=1;
            if(curqts[i]=='(')  {brcnt+=1; }
        }else if(curqts[i]==')'){brcnt-=1; }
        
        if(qtscnt==1)       qts[0]+=curqts[i];
        else if(qtscnt==2)  qts[1]+=curqts[i];
        else if(qtscnt==3)  qts[2]+=curqts[i];
        else                qts[3]+=curqts[i];
    }
    for(int i=0; i<4; i++){
        if(i==0)        qts_recursive(qts[i], size/2, x, y+size/2);
        else if(i==1)   qts_recursive(qts[i], size/2, x, y);
        else if(i==2)   qts_recursive(qts[i], size/2, x+size/2, y);
        else            qts_recursive(qts[i], size/2, x+size/2, y+size/2);
    }
}//end of qts_recursive()
void qts(int size){
    string quad;
    cin >> quad;
    qts_recursive(quad, size, 0 ,0);
    // for(int i=0; i<size;i++)  {
    //     for(int j=0;j<size;j++) {
    //         cout << myimg[i][j];
    //     }
    //     cout << '\n';
    // }
}//end of qts()

void img_recursive(int size, int x, int y){
    char curimg = myimg[x][y];
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++)
            if (myimg[i][j] != curimg){
                cout << '(';
                img_recursive(size/2, x, y+size/2);
                img_recursive(size/2, x, y);
                img_recursive(size/2, x+size/2, y);
                img_recursive(size/2, x+size/2, y+size/2);
                cout << ')';
                return;
            }

    cout << curimg;
}//end of img_recursive()
void img(int size){
    for (int i=0; i<size; i++){
        cin >> myimg[i];
    }  
    img_recursive(size, 0, 0);
}//end of img()

int main(void){
    int k; string order;
    cin >> k >> order;
    int size=pow(2, k);

    if (order=="QTS") qts(size);
    else if(order=="IMG") img(size);

    for(int i=0; i<size;i++)  {
        for(int j=0;j<size;j++) {
            cout << myimg[i][j];
        }
        cout << '\n';
    }
    return 0;
}

