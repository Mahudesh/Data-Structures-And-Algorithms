class Solution {
public:
bool isSetBit(int n, int i)
{
    if((n&(1<<i-1))!=0)
    return true;
    return false;
}
    uint32_t reverseBits(uint32_t n) 
    {
        unsigned int ans=0;
        //There Are Total 32 Bits In Unsigned Int
        //If ith Bit Is A Set Bit ThenBy Reverse Left Shift Of 32-ith Bit Should Be The Set Bit
        //U Can Ask Why Should I Reverse 32nd Bit Since It Is Sign Representation
        //But Here Given As Unsigned Int
        //For Unsigned Int The 32nd Bit Is Not Allocated For Sign Representation
        //Hence I Have To Reverse The 32nd Bit Also
        for(int i=1;i<=32;i++)
        {
            if(isSetBit(n,i))
            {
                ans=ans|(1<<(32-i));
            }
        }
        return ans;

    }
};
