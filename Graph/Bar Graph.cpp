#include<iostream>
using namespace std;
int main()
{
    int a[5],t,i,j,max,b[5];
    cout<<"Enter the marks of the students";
    for(i=0;i<5;i++)  //to obtain the bar graph of the marks obtained by students
    cin>>a[i];
      max=a[0];
     for(i=1;i<5;i++)
     {
      if(a[i]>max)
      max=a[i];
      }
      for(i=0;i<5;i++)
      b[i]=max;
      for(i=0;i<max;i++)
      {
       for(j=0;j<5;j++)
       {
                       if(max-b[j]>a[j])
                       {
                                    cout<<"   ";

                                    }
                                    else
                                    {
                                        cout<<"*  ";
                                        b[j]--;
                                        }
                                        }
                                        cout<<"\n";
                                        }
                                        //system("pause");
                                        }


