Takahashi has a garden with ‘n’ beautiful flowers in a row. He waters exactly “arr[i]” liters of water to ith flowers from left to right daily to keep them beautiful. He has a container that can contain ‘k’ liters of water. But he follows certain rules to water all the plants:

Water a plant if he has sufficient water in the container, otherwise refill it.

You can only refill at the water tank which is placed one step before the first flower.
Takahashi wants to know the minimum number of steps he needs to water all the flowers.

For Example :
Let arr = {3, 5, 1, 2}, k = 6

Now in this example, he will first move to the first flower and water it. Now his container contains only 3 liters of water, hence he will refill the container, so he goes 1 step back and refills, comes to the 2nd flower, after watering the second flower, he still has 1 liter of water and 1 flower left. So he will water that flower and return to refill. Now he will come to the last flower and water it. 
Hence the total steps taken are: 1 + 1 + 2 + 1 + 3 + 4 = 12.

int totalSteps(int n, int k, vector<int> &flowers)
 {
    //    Write your code here
    int steps=0;
    int water=k;
    if(flowers[0]<=water)
    {
        water=water-flowers[0];
        steps++;
    }
    else
    {
        return 0;
    }
    for(int i=0;i<flowers.size()-1;i++)
    {
        if(flowers[i+1]<=water)
        {
            water=water-flowers[i+1];
            steps++;
        }
        else
        {
            steps=steps+(i-0+1);
            water=k;
            steps+=(0+i+1+1);
            water=water-flowers[i+1];
        }
    }
    return steps;
}
