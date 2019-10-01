
ll p[N], size[N];

void init( ) {
    rep(i, 1, N){
        p[i] = i;
        size[i] = 1;
    }
}

int root(int v) {
    if (v == p[v])
        return v;
    return p[v] = root(p[v]);
}

void merge(int a, int b) {
    a = root(a);
    b = root(b);
    if (a != b){
        if(size[a] < size[b])
            swap(a, b);
        p[b] = a;
        size[a] = max(size[a], size[b]);
    }
}


// C++ program to implement Solovay-Strassen 
// Primality Test 
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

// modulo function to perform binary exponentiation 
long long modulo(long long base, long long exponent, 
									long long mod) 
{ 
	long long x = 1; 
	long long y = base; 
	while (exponent > 0) 
	{ 
		if (exponent % 2 == 1) 
			x = (x * y) % mod; 

		y = (y * y) % mod; 
		exponent = exponent / 2; 
	} 

	return x % mod; 
} 

// =============================================
//                 Jacobi Function              
// =============================================


ll power(ll a, ll n, ll p){
	ll res = 1;
	while( n > 0){
		if( n%2 == 1)
			res = (res * a) % p;
		a = (a*a)%p;
		n = n / 2;
	}
	return res%p;
}

int legendre(int a, int p){
	if(a%p == 0)
		return 0;
	else if( power(a,(p-1)/2, p) == 1)
		return 1;
	else
		return -1;
}

int jacobi(int a, int n) {
	std::vector<int> v,v1;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			v.push_back(i);
		
		int cnt=0;
		while(n%i==0)
		{
			n/=i;
			cnt++;
		}
		v1.push_back(cnt);
	}
	}
	if(n!=1){
		v.push_back(n);
		v1.push_back(1);
	}
		
	int ans=1;
	for(int i = 0;i<v.size(); i++)
	{
		ans*=pow(legendre(a,v[i]),v1[i]);
	}
	return ans;
}

// =============================================
// To perform the Solovay-Strassen Primality Test 
bool solovoyStrassen(long long p, int iterations) 
{ 
	if (p < 2) 
		return false; 
	if (p != 2 && p % 2 == 0) 
		return false; 

	for (int i = 0; i < iterations; i++) 
	{ 
		// Generate a random number a 
		long long a = rand() % (p - 1) + 1; 
		long long jacobian = (p + jacobi(a, p)) % p; 
		long long mod = modulo(a, (p - 1) / 2, p); 

		if (!jacobian || mod != jacobian) 
			return false; 
	} 
	return true; 
} 

// Driver Code 
int main() 
{ 
	int iterations = 50; 
	long long num1 = 1000000007; 
	long long num2 = 20; 

	if (solovoyStrassen(num1, iterations)) 
		cout<< num1 << " is prime."; 
	else
		cout<< num1 << " is composite."; 

    cout<< endl;
	if (solovoyStrassen(num2, iterations)) 
		cout<< num2 << " is prime."; 
	else
		cout<< num2 << " is composite.";  

	return 0; 
} 
