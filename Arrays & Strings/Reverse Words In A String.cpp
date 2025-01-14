public class Solution 
{
	public static String reverseString(String str) 
	{
		//Write your code here
		String temp[]=str.trim().split("\\s+");
		// String ans="";
		StringBuilder sb=new StringBuilder();
		for(int i=temp.length-1;i>=0;i--)
		{
			// ans=ans+temp[i];
			// ans=ans+" ";
			sb.append(temp[i]);
			if(i!=0)
			sb.append(" ");
		}
		// ans=ans.trim();
		return sb.toString();
	}
}
