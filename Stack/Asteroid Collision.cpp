#LeetCode: 735
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<asteroids.size();i++)
        {
            //If It Is A Positive Asteroid Then There Is Noo Problem Just Push It Into Stack
            //No Collision Occurs
            //Problem Arises When You Encounter A Negative Asteroid
            if(asteroids[i]>=0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                //If It Is Negative Asteroid
                //Check For Previous Element Using st.top() 
                //If It Is Smaller Than Upcoming Asteroid Then It Will Destroy So Pop Out
                //Else Skip The Asteroid
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]))
                {
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(asteroids[i]))
                {
                    st.pop();
                    //If It Is Equal Size Then Both Asteroid Will Be Destroyed.
                    continue;
                }
                //If There Is A Negative Asteroid Which Is Very Big
                //Then It Destroys All The Positive Asteroids Which Results In Stack Empty
                //If So Push It Into Stack Because It Wont Destroy Any Positive Asteroid
                //Because There Is No Positive Asteroid
                if(st.empty() || st.top()<0)
                {
                    st.push(asteroids[i]);
                }

            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};
