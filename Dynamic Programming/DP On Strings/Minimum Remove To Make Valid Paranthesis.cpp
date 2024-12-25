class Solution {
public:
    string minRemoveToMakeValid(string s)
     {
        int n=s.length();
        string temp;
        int opening=0;
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                opening++;
                temp.push_back(ch);
            }
            //Never Pushes If There Are Closing Bracket Without Any Opening Bracket
            else if(ch==')' && opening>0)
            {
                opening--;
                temp.push_back(ch);
            }
            else if(isalpha(ch))
            {
                temp.push_back(ch);
            }
        }
        //If Still Opening Brackets Exists Then I Need To Remove It From The Backwards
        //Remove From BackWards So That Before The Current Removing '(' Of All Previous '('
        //Will 100% Sure That They Will Have A Correct Match ')' In Future
        string ans;
        if(opening>0)
        {
            for(int i=temp.length()-1;i>=0;i--)
            {
                if(opening>0 && temp[i]=='(')
                {
                    opening--;
                }
                else
                {
                    ans.push_back(temp[i]);
                }
            }

            reverse(ans.begin(),ans.end());
            return ans;
        }
        else
        {
            //If There Are No Extra Openings Then temp Is A Valid String
            //Because I Can Say That '(' Extras Are Handled In First Loop Itself
            return temp;
        }
    }
};
