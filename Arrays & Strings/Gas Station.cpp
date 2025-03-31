class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
     {
        // int ind=-1;
        // int n=gas.size();
        // int i=0;
        // int petrol=0;
        // while(i<n)
        // {
 
        //     int j=i;
        //     int cnt=0;
        //     petrol=0;
        //     while(cnt<n)
        //     {    

        //         petrol=petrol+gas[j];
        //         petrol=petrol-cost[j];

        //         if(petrol<0)
        //         break;

        //         cnt++;


        //         j=(j+1)%(gas.size());
        //     }

        //     if(cnt==n)
        //     return i;

        //     if(j<i) break;

        //     i=j+1;
        // }
        // return ind;



        //Optimal Solution

        //Check For Total Gas Available
        int tot_gas=0,tot_cost=0;
        for(int i=0;i<gas.size();i++)
        {
            tot_gas+=gas[i];
            tot_cost+=cost[i];
        }
        if(tot_gas<tot_cost) return -1;

        int start=0;
        int tank=0;
        for(int i=0;i<gas.size();i++)
        {
            tank=tank+gas[i];
            tank=tank-cost[i];

            if(tank<0)
            {
                tank=0;
                start=i+1;
            }
        }
        return start;
    }
};
