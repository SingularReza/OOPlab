#include<iostream> 
using namespace std; 
  
#define MAX 2000
  
void factorial(int n) { 
    int arr[MAX]; 
  
    // Initialize array
    arr[0] = 1; 
    int arr_size = 1; 
  
    // factorial
    for (int x=2; x<=n; x++) {
        arr_size = multiply(x, arr, arr_size); 
    }
  
    cout << "Factorial of given number is \n"; 
    for (int i=arr_size-1; i>=0; i--) {
        cout << arr[i]; 
    }
} 
  
int multiply(int x, int arr[], int arr_size) 
{ 
    int carry = 0;  // Initialize carry 
  
    for (int i=0; i<arr_size; i++) { 
        int temp = arr[i] * x + carry;    
        arr[i] = temp % 10;    
        carry  = temp/10;     
    } 
  
    while (carry) { 
        arr[arr_size] = carry%10; 
        carry = carry/10; 
        arr_size++; 
    } 
    return arr_size; 
} 
   
int main() { 
    int input;
    cin>>input;
    factorial(input); 
    return 0; 
} 