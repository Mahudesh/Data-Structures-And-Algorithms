bool isKthBitSet(int n, int k)
{
    // Write your code here.
    //Using Left Shift Operator By Trying To Keep Set Bit Below The ith Bit
    //And Take AND Operation To Check Whether The Number Is Greater Than 0 Or Not
    int num=n&(1<<k-1);
    if(num>0)
    return true;
    return false;

    //Using Right Shift Operator By Moving The ith Bit To Right Most
    //And Take AND Operation To Check Whether The Number Is Equal To 1 Or Not
     n=n>>k-1;
    if((n&1)==1)
    return true;
    return false;

}
