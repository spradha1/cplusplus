#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int width, offset;
    cout << "This is a diamond display program." << endl;
    cout << "First enter an odd diamond width: ";
    cin >> width;
    cout << "Now enter lateral offset: ";
    cin >> offset;

    //correction for even input
    if((width%2)==0){
        ++width; //post increment here would keep the value constant for the first loop execution
        cout << "You entered even width. Correcting your error by incrementing width by 1...." << endl;
    }

    //top half
    for(int i=0; i<width/2; i++){
        for(int j=0; j<offset; j++){
            cout << " ";
        }
        for(int k=(width/2)-i; k>0; k--){
            cout << " ";
        }
        for(int a=0; a<2*i+1; a++){
            cout << "*";
        }
        cout << "\n";
    }

    //midway line
    for(int j=0; j<offset; j++){
        cout << " ";
    }
    for(int l=0; l<width; l++){
        cout << "*";
    }
    cout << "\n";

    //bottom half
    for(int m=(width/2)-1; m>=0; m--){
        for(int j=0; j<offset; j++){
            cout << " ";
        }
        for(int k=(width/2)-m; k>0; k--){
            cout << " ";
        }
        for(int a=2*m+1; a>0; a--){
            cout << "*";
        }
        cout << "\n";
    }
}
