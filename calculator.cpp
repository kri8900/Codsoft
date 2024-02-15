#include<iostream>
#include<stdlib.h>
using namespace std;
double power(double m,int n)
{
    double pow=1;
    while (n!=0)
    {
        pow= pow*m;
        n--;
    }
    return pow;
}
float sum(float x, float y)
{
    float sum = x+y;
    return sum;
}
float sub(float x, float y)
{
    float sub = x-y;
    return sub;
}
float mult(float x, float y)
{
    float multi = x*y;
    return multi;
}
float div(float x,float y)
{
    float div = x/y;
    return div;
}
int main (){
    int choice;float a,b;
    do
    {
        cout<<"\n\n\n1. Addition"<<endl;
        cout<<"2. Subtraction"<<endl;
        cout<<"3. Multiplication"<<endl;
        cout<<"4. Division"<<endl;
        cout<<"5. m^n"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"\nEnter your choice --->\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter 1st number :";
            cin>>a;
            cout<<"Enter 2nd number :";
            cin>>b;
            cout<<endl<<a<<" + "<<b<<" = "<<sum(a,b)<<endl;
            break;
        case 2:
            cout<<"\nEnter 1st number :";
            cin>>a;
            cout<<"Enter 2nd number :";
            cin>>b;
            cout<<endl<<a<<" - "<<b<<" = "<<sub(a,b)<<endl;
            break;
        case 3:
            cout<<"\nEnter 1st number :";
            cin>>a;
            cout<<"Enter 2nd number :";
            cin>>b;
            cout<<endl<<a<<" * "<<b<<" = "<<mult(a,b)<<endl;
            break;
        case 4:
            cout<<"\nEnter 1st number :";
            cin>>a;
            cout<<"Enter 2nd number :";
            cin>>b;
            cout<<endl<<a<<" / "<<b<<" = "<<div(a,b)<<endl;
            break;
        case 5:
            cout<<"\nEnter 1st number :";
            cin>>a;
            cout<<"Enter 2nd number :";
            cin>>b;
            cout<<endl<<a<<" ^ "<<b<<" = "<<power(a,b)<<endl;
            break;

        case 6:
            cout<<"   Thank You  ";
            exit(0);
            //break;
        
        default:
            cout<<"      !!error!!    "<<" \nplease enter the correct choice.";
            break;
        }
    } while (choice>0);
    
}