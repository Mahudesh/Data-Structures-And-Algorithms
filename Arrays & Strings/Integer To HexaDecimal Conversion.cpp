#include <bits/stdc++.h> 
string toHex(int num) {
	// Write your code here.
	stringstream ss;

	ss << uppercase << hex << num;

	return ss.str();
}
