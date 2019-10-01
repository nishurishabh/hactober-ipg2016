

int bfs(int s) {
    queue<int> q;
    vector<bool> visited(n);
    int visCount = 0;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
    	
        int c = q.pop();
        for (auto v: graph[c]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
                
        visCount += 1;
    }

    return visCount;
}

// also print primes 
// C++ program to find the prime numbers 
// between a given interval 

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	int a, b, i, j, flag; 
	cout << "Enter lower bound of the interval: "; 
	cin >> a; 

	
	cout << "\nEnter upper bound of the interval: "; 
	cin >> b;

	
	cout << "\nPrime numbers between "
		<< a << " and " << b << " are: "; 

	
	for (i = a; i <= b; i++) 
	{ 
		
		if (i == 1 || i == 0) 
			continue; 

		
		flag = 1; 

		for (j = 2; j <= i / 2; ++j) 
		{ 
			if (i % j == 0) 
			{ 
				flag = 0; 
				break; 
			} 
		} 

		if (flag == 1) 
			cout << i << " "<<endl; 
	} 

	return 0; 
} 

