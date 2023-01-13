//
// Created by Sivasubramani on 18/12/22.
//

#include "Console.h"

Console *Console::instance = 0;

void Console::printValue(vector<int> A,string type) {
//    return;
    cout<<"********* "<<type<<" **********"<<endl;
    for(int i=0;i<A.size();i++) cout<<A[i]<<"\t";
    cout<<"\n********* "<<"ending"<<" **********\n"<<endl;
}

