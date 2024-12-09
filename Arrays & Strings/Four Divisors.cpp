Problem statement
Ninja was planning to propose to his crush, Nina, with his spectacular martial arts moves. But Nina was more interested in numbers and divisors, so she gave Ninja a challenge to complete. If Ninja solves it, only then she will date him.

Nina gave him an array of positive integers, ‘ARR’ and asked him to find the sum of divisors of the integers in ‘ARR’ with exactly four divisors. In case there is no such integer with exactly four divisors, then the answer is 0. Ninja has been struggling for a very long time, so he needs your help to solve the problem.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
1 <= N <= 2000
1 <= ARR[ i ] <= 10 ^ 5

Where ‘T’ is the number of test cases, ‘N’ is the number of integers in the array, ‘ARR’ and ‘ARR[ i ]’ is the ‘i’th element in the ‘ARR’ array.

Time limit: 1 second
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Sample Input 1:
2
4
2 5 6 15
3
4 18 21
Sample Output 1:
36
32
Explanation of Sample Output 1:
Test Case 1 :  
Divisors of 2 are 1 and 2.
Divisors of 5 are 1 and 5.
Divisors of 6 are 1, 2, 3 and 6.
Divisors of 15 are 1, 3, 5 and 15.
Since 6 and 15 have exactly four divisors. Sum of their divisors is (1 + 2 + 3 + 6) + (1 + 3 + 5 + 15) = 36.

Test Case 2 : 
Divisors of 4 are 1, 2 and 4.
Divisors of 18 are 1, 2, 3, 6, 9 and 18.
Divisors of 21 are 1, 3, 7 and 21.
Since only 21 has exactly four divisors. Sum of its divisors is (1 + 3 + 7 + 21) = 32.
Sample Input 2:
2
5
7 35 64 11 8
6
27 13 42 25 25 25
Sample Output 2:
63
40

#include <bits/stdc++.h> 
int sumFourDivisors(vector<int> &arr, int n)
{
    // Write your code here.
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int ele=arr[i];
        int div=0;
        int sum=0;
        for(int i=1;i<=sqrt(ele);i++)
        {
            if(ele%i==0)
            {
                sum=sum+i;
                div++;
                if(ele/i!=i)
                {
                    sum=sum+(ele/i);
                    div++;
                }
            }
        }
           
        if(div==4)
        {
            ans=ans+sum;
        }
    }
    return ans;
}
