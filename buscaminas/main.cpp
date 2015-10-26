//
//  main.cpp
//  buscaminas
//
//  Created by Zareek Galvan on 1/20/15.
//  Copyright (c) 2015 Zareek Galvan. All rights reserved.
//

#include <iostream>

using namespace std;
#include <sstream>
#include <string.h>

int main()
{
    int m,n;
    string aux;
    int times, loop=0;
    cin>>times;
    while (loop<times && times<21)
    {
        cin>>m>>n;
        if (m<11 && n<11)
        {
            char matriz[m+2][n+2];
            for (int z=1; z<m+1; z++)
            {
                string imp;
                cin>>imp;
                for (int y=1, x=0; y<n+1; y++, x++)
                {
                    matriz[z][y]=imp[x];
                }
            }
            bool e=false, f=false;
            for (int z=1; z<m+1; z++)
            {
                for (int y=1; y<n+1; y++)
                {
                    if (matriz[z][y]=='*')
                    {
                        e=true;
                    }
                }
            }
            for (int z=1; z<m+1; z++)
            {
                for (int y=1; y<n+1; y++)
                {
                    if (matriz[z][y]!='*' && matriz[z][y]!='.')
                    {
                        f=true;
                    }
                }
            }
            if (e==true)
            {
                for (int z=1; z<m+1; z++)
                {
                    for (int y=1; y<n+1; y++)
                    {
                        if (matriz[z][y]!='*')
                        {
                            int a=0;
                            stringstream s;
                            if (matriz[z-1][y-1]=='*')
                            {
                                a++;
                            }
                            if (matriz[z-1][y]=='*')
                            {
                                a++;
                            }
                            if (matriz[z-1][y+1]=='*')
                            {
                                a++;
                            }
                            if (matriz[z][y-1]=='*')
                            {
                                a++;
                            }
                            if (matriz[z][y+1]=='*')
                            {
                                a++;
                            }
                            if (matriz[z+1][y-1]=='*')
                            {
                                a++;
                            }
                            if (matriz[z+1][y]=='*')
                            {
                                a++;
                            }
                            if (matriz[z+1][y+1]=='*')
                            {
                                a++;
                            }
                            s<<a;
                            string temp=s.str();
                            char* c=  (char*)temp.c_str();
                            char l= *c;
                            matriz[z][y]=l;
                        }
                    }
                }
            }
            //checar diferentes dimensiones de input ej 3x3 -> 3,2,3
            
            
            if (e!=false && f!=true)
            {
                cout<<"Caso "<<loop+1<<":"<<endl;
                if (m==1 && n==1)
                {
                    cout<<"0"<<endl<<endl;
                }
                if (f==true)
                {
                    cout<<endl<<endl;
                }
                for (int z=1; z<m+1; z++)
                {
                    for (int y=1; y<n+1; y++)
                    {
                        cout<<matriz[z][y];
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
            if (e==false && f==false)
            {
                cout<<"Caso "<<loop+1<<":"<<endl;
                for (int z=1; z<m+1; z++)
                {
                    for (int y=1; y<n+1; y++)
                    {
                        matriz[z][y]='0';
                        cout<<matriz[z][y];
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
            
        }
        loop++;
    }
}
