void MyStack ::push(int x) 
{
    top++;
    arr[top]=x;
    // Your Code
}

// Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==-1)
    return -1;
    int x=arr[top];
    top--;
    return x;
}


void MyStack ::push(int x) 
{
    top++;
    arr[top]=x;
    // Your Code
}

// Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==-1)
    return -1;
    int x=arr[top];
    top--;
    return x;
}
