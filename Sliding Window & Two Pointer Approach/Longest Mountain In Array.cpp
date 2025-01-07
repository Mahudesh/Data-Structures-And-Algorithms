clude <bits/stdc++.h> 
int longestMountain(int *arr, int n)
{
    // Write your code here.
//    int n=arr.size();
        int maxLen=0;

        if(n<3)
        return 0;
        for(int i=1;i<n-1;)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int l=i;
                int r=i;
                while(l>0 && arr[l]>arr[l-1])
                l--;

                while(r<n-1 && arr[r]>arr[r+1])
                r++;

                if(i!=r && i!=l)
                maxLen=max(maxLen,r-l+1);
                i=r;
            }
            else
            {
                i++;
            }
        }
        return maxLen;
}
