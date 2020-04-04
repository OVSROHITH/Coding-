3. UVa 543 - Goldbach’s Conjecture

https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484



```
#include<iostream> 
#include<cmath> 
using namespace std; 
int primeNumbers[]={2, 3, 4, 5, 7, 9, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41,  
43, 47, 49, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,  
121, 127, 131, 137, 139, 149, 151, 157, 163, 167, 169, 173, 179, 181, 191, 193,  
197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,  
283, 289, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 361, 367, 373,  
379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,  
467, 479, 487, 491, 499, 503, 509, 521, 523, 529, 541, 547, 557, 563, 569, 571,  
577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661,  
673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773,  
787, 797, 809, 811, 821, 823, 827, 829, 839, 841, 853, 857, 859, 863, 877, 881,  
883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 961, 967, 971, 977, 983, 991,  
997, 1009,1013}; 
bool IsPrime(int num) 
{ 
    if(num == 0) 
    { 
        return true; 
    } 
    int i=0; 
    while(primeNumbers[i]<=sqrt(num) && primeNumbers[i]!=1013) 
    {  
         if(num % primeNumbers[i] == 0) 
         {  
              return false; 
         } 
         i++; 
    } 
   return true; 
} 
int findPrimes(int n) 
{ 
     for(int i=2;i<n/2+1;i++) 
     { 
             if(IsPrime(i) && IsPrime(n-i)) 
             { 
                           cout<<n<<" = "<<i<<" + "<<n-i<<"\n"; 
                           return 0; 
             } 
     } 
} 
int main() 
{ 
    int m=-1; 
    while(m!=0) 
    { 
        cin>>m; 
        if(m==0) return 0;        
        findPrimes(m); 
         
    }     
    return 0; 
}
================================================================================================================

#include<stdio.h> 
int mark[1000000]={0}, Prime[100000], Pt = 0; 
void Sieve() { 
	int i, j; 
	for(i = 3; i < 1000000; i += 2) { 
		if(mark[i] == 0) { 
			Prime[Pt++] = i; 
			for(j = 3; i*j < 1000000; j += 2) 
				mark[i*j] = 1; 
		} 
	} 
} 
int main() { 
	int n, i; 
	Sieve(); 
	while(scanf("%d", &n) == 1 && n) { 
		int x, y, flag = 0; 
		for(i = 0; i < Pt; i++) { 
			x = Prime[i], y = n-Prime[i]; 
			if(x > y)	break; 
			if(mark[x] == 0 && mark[y] == 0) { 
				printf("%d = %d + %d\n", n, x, y); 
				flag = 1; 
				break; 
			} 
		} 
		if(!flag) 
			puts("Goldbach's conjecture is wrong."); 
	} 
    return 0; 
}
```
