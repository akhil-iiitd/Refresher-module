#include<iostream>
#include<string>
#include<cmath>
using namespace std;


void merge(int arr[],int low,int mid,int high)
{
    int counter=low;
    int temp[100];
    int i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]>=arr[j])
        {
            temp[counter]=arr[j];
            j++;
            
        }
        else
        {
            temp[counter]=arr[i];
            i++;
        }
            
        counter++;
    }

    while(i<=mid)
    {
        temp[counter++]=arr[i++];
    }
        
    
    while(j<=high)
    {
        temp[counter++]=arr[j++];
    }
    
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
}
void mergesortRecursive(int arr[],int low, int high)
{
    
    if(low==high)
        return;
    int mid=(low+high)/2;
    mergesortRecursive(arr,low,mid);
    mergesortRecursive(arr,mid+1,high);
    merge(arr,low,mid,high);
}


void mergesortIterative(int arr[],int arr_length)
{
    int low,high,mid,i,j;
    for(i=2;i<=arr_length;i=i*2)
    {
        for(j=0;j+i-1<arr_length;j=j+i)
        {
            low=j;
            high=j+i-1;
            mid=(low+high)/2;
            merge(arr,low,mid,high);
        }
    }

    if(i/2<arr_length)
    merge(arr,0,i/2-1,arr_length-1);

}


int main()
{

    int arr1[100],arr2[100],n1=0,n2=0;

    string input_string;
    cout<<"Enter the array to be sorted with elements separated by comma: ";
    cin>>input_string;

    int string_length=input_string.length();
    string temp_string="";
    for(int i=0;i<string_length;i++)
    {
        if(input_string[i]!=',')
        {
            temp_string=temp_string+(input_string[i]);
        }
        else{
            cout<<temp_string<<endl;
            if(temp_string!="")
            {
                arr1[n1++]=stoi(temp_string)-'\0';
                arr2[n2++]=stoi(temp_string)-'\0';
            }
                
            temp_string="";
        }
        
    }
    if(temp_string!="")
    {
        arr1[n1++]=stoi(temp_string)-'\0';
        arr2[n2++]=stoi(temp_string)-'\0';
    }

   

    mergesortRecursive(arr1,0,n1-1);
    
    cout<<"Sorted array by recursion is : \n";
    for(int i=0;i<n1;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<"\n\n";

    mergesortIterative(arr2,n2);
    cout<<"Sorted array by iteration is : \n";
    for(int i=0;i<n2;i++)
    {
        cout<<arr2[i]<<" ";
    }

    

}