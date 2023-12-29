#include<iostream>
#include<string.h>
using namespace std;

int counter=0;
struct P
{
    int val,pri;
}P[100];

int insertPQ(struct P P[],int val,int pri,int counter)
{

    int i=0,j=0;
    while(P[i].pri<pri && i<counter)
    {
        i++;
    }
    j=counter;
    while(j>i)
    {
        P[j]=P[j-1];
        j--;
    }
    P[i].val=val;
    P[i].pri=pri;
    return 1;
}

int findPQ(struct P P[],int val,int len)
{
    
    for(int i=0;i<len;i++)
    {
        if(P[i].val==val)
        {
            return i;
        }
    }

    return -1;
}

void deletePQ(struct P P[],int val,int len)
{
    int ret_val=findPQ(P,val,len);
    if(ret_val!=-1)
    {
        for(int i=ret_val;i<len-1;i++)
        {
            P[i]=P[i+1];
        }

        counter--;
    }
    else
    {
        cout<<"Element not found \n";
    }
}

void popPQ(struct P P[])
{
    if(counter==0)
    {
        cout<<"PQueue empty"<<endl;
        return;
    }
    cout<<"Element with value "<<P[counter-1].val<<" and max priority "<<P[counter-1].pri<<" popped \n";
    counter--;
}

int main()
{
    
    int inp;
    char ch;
    string input_val;
    int while_counter=-1;
    while(true)
    {
        while_counter++;
        if(while_counter!=0)
        {
            cout<<">>Do you want to perform more operations? Enter 'Y' or 'N': "<<endl;
            cin>>ch;
            if(ch=='N')
            {
                cout<<">>Program ended. "<<counter<<" element remaining in the queue. "<<endl;
                exit(0);
            }
        }
        cout<<">>Which operation do you want to perform: 1:Insert, 2:Find, 3:Delete, 4:Pop : ";
        cin>>inp;
        int val,pri;
        switch(inp)
        {
            case 1:{
                cout<<">>Please enter the value,priority to be inserted:";
                
                cin>>input_val;
                int input_val_length=input_val.length();
                string temp_string="";
                for(int i=0;i<input_val_length;i++)
                {
                    if(input_val[i]!=',')
                    {
                        temp_string=temp_string+(input_val[i]);
                    }
                    else
                    {
                        if(temp_string!="")
                        {
                            val=stoi(temp_string)-'\0';
                            temp_string="";
                        }
                        for(int j=i+1;j<input_val_length;j++)
                        {
                            temp_string=temp_string+(input_val[j]);
        
                        }
                        //cout<<"\n\n"<<temp_string<<"\n\n";
                        if(temp_string!="")
                        {
                            pri=stoi(temp_string)-'\0';
                        }

                    }
                }
                
                counter+=insertPQ(P,val,pri,counter);
                
                
                break;
            }

            case 2:
            {
                cout<<">>Please enter the value to be searched: ";
                int val;
                cin>>val;
                int ret_val=findPQ(P,val,counter);
                if(ret_val!=-1)
                {
                    cout<<"Value = "<<val<<" found with priority "<<P[ret_val].pri<<endl;
                }
                else
                {
                    cout<<"Value = "<<val<<" not found"<<endl;
                }
                
                    break;
            }

            case 3:
            {
                cout<<"Enter the value to deleted : ";
                int ele;
                cin>>ele;
                deletePQ(P,ele,counter);
                
                break;
            }

            case 4:
            {
                popPQ(P);
                
                
                break;

            }

            

            
        }
        /*for(int i=0;i<counter;i++)
            {
                cout<<P[i].val<<" ";
            }
            cout<<endl;
            for(int i=0;i<counter;i++)
            {
                cout<<P[i].pri<<" ";
            }
            cout<<endl;*/
    }

}