// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     int n;
//     cin >> n;
//     int id[n];
//     int ov[n];
//     int v[n];
//     for(int i = 0;i < n;i++)
//     {
//         cin >> id[i];cin >> v[i];
//         ov[i] = v[i];
//     }
//     sort(v,v+n);
//     int k;
//     cin >> k;int cnt = 0;int b;

//     for(int i = 0;i < n-1;i++)
//     {
//         if(v[i] != v[i+1])cnt++;
//         if(cnt == k){
//             b = v[i];break;
//         }
//     }
//     cout << b;
    
//     int l;
//     for(int i = 0;i < n;i++)
//         if(ov[i] == b){l = i;break;}

//     printf("The student with id number %d will be rewarded",id[l]);
    

    
// }


#include <bits/stdc++.h>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define E_FOR(i, a, b) for (int i=a; i<=b; i++)
#define FOR(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define ll64 unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define all_u(ar,val) ar.begin(), ar.end(),val
#define get_ind_lo(ar,val) int(lower_bound(all_u(ar,val)) - ar.begin());
#define get_ind_up(ar,val) int(upper_bound(all_u(ar,val)) - ar.begin());
#define pb push_back
#define pf push_front
#define INF 500000000
#define maxN 1000001
using namespace std;

bool isP[maxN];
vector<int> prime;

void Sieve() {
    Fill(isP, true);
    isP[0] = isP[1] = false;
    for (int i=4; i<maxN; i+=2) isP[i] = false;
    for (int i=3, lm=(int)sqrt(maxN); i<=lm; i+=2)
        if (isP[i]) for (int j=i*i; j<maxN; j+=i+i)
            isP[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (isP[i]) prime.pb(i);
}

void Solve(int n) {
    vector<int> num, t;
    int p = 0, np = prime.size();
    while (p<np && n>1) {
        if (n%prime[p]==0) {
            int Count = 0;
            while (n>1 && n%prime[p]==0) {
                n /= prime[p];
                Count++;
            }
            num.pb(prime[p]);
            t.pb(Count);
        }
        p++;
    }
    n = num.size();
    if (n) printf("%d %d", num[n-1], t[n-1]);
    for (int i=n-2; i>=0; i--)
        printf(" %d %d", num[i], t[i]);
    printf("\n");
}


int main(){
    Sieve();
    string s;
    int a[10000];


    while(getline(cin,s) && s != "0"){
        int ind=0;
        long long val = 1;
        stringstream ss(s);
        vector<pair<int ,int>>p;

        while(ss >> a[ind]){
            ind++;
        }
        
        // for(int i = 0;i < ind;i++)cout << a[i] << " ";
        for(int i = 0;i < ind-1;i++){
            val *= pow(a[i],a[i+1]);
        }
        
        val--;
        Solve(val);
    }
}