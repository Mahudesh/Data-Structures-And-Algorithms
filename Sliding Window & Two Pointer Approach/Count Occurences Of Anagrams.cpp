class Solution{
public:
	int search(string pat, string txt) 
	{
	    // code here
	    int req=pat.length();
	    int l=0;
	    int r=0;
	    unordered_map<char,int>Map;
	    int cnt=0;
	    for(auto it: pat)
	    Map[it]++;
	    while(r<txt.length())
	    {
	        if(Map[txt[r]]>0)
	        {
	            req--;
	        }
	        Map[txt[r]]--;
	        if(req==0)
	        cnt++;
	        while(r-l+1 == pat.length())
	        {
	            if(Map[txt[l]]>=0)
	            {
	                req++;
	            }
	            Map[txt[l]]++;
	            l++;
	        }
	        r++;
	    }
	    return cnt;
	}

};
