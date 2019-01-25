#include<iostream> 
using namespace std; 
  
#define MAX 2000
  
int multiply(int x, int arr[], int arr_size); 
  
void factorial(int n) 
{ 
    int arr[MAX]; 
  
    // Initialize arrult 
    arr[0] = 1; 
    int arr_size = 1; 
  
    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n 
    for (int x=2; x<=n; x++) 
        arr_size = multiply(x, arr, arr_size); 
  
    cout << "Factorial of given number is \n"; 
    for (int i=arr_size-1; i>=0; i--) 
        cout << arr[i]; 
} 
  
int multiply(int x, int arr[], int arr_size) 
{ 
    int carry = 0;  // Initialize carry 
  
    // One by one multiply n with individual digits of arr[] 
    for (int i=0; i<arr_size; i++) 
    { 
        int prod = arr[i] * x + carry; 
  
        // Store last digit of 'prod' in arr[]   
        arr[i] = prod % 10;   
  
        // Put arrt in carry 
        carry  = prod/10;     
    } 
  
    while (carry) 
    { 
        arr[arr_size] = carry%10; 
        carry = carry/10; 
        arr_size++; 
    } 
    return arr_size; 
} 
  
// Driver program 
int main() 
{ 
    int input;
    cin>>input;
    factorial(input); 
    return 0; 
} 