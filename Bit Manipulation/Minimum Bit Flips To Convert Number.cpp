class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        //Doing XOR(Difference) Operation Will Give  The Actual Bit Indices Which Needs To Be Flipped
        int ans=start^goal;
        int cnt=0;
        //If I Can Count The Set Bits After Doing XOR Operation 
        //Then I Can Obtain Minimum Bit Flips Required TO Achieve The Goal
        while(ans>=1)
        {
            if(ans&1==1)
            cnt++;
            ans=ans>>1;
        }
        return cnt;
    }
};
