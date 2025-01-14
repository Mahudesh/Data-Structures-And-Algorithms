int countRectangles(int num)
{
	// Write your code here

	//Formula For Number Of Rectangles In NXN Chess Board
	long long mod=1e9+7;
	long long n=num;
	long long totRectangles = ((n*(n+1)/2)%mod * (n*(n+1)/2))%mod;

	//Formula For Calculating Number Of Squares In N Size
	//1^2 + 2^2 + 3^3 + 4^4 + 5^5 = Sum Of All Squares

	long long totSquares = (n*(n+1)%mod*(2*n+1)%mod)%mod;

	totSquares=(totSquares*166666668)%mod;

	long long res = (totRectangles-totSquares)%mod;

	return (int)(res % mod);


}
