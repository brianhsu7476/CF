// Online C++ compiler to run C++ program online
#include <iostream>
using  namespace std;
int Xor(int a,int b){
    return a^b;
}
int main() {
    // Write C++ code here
    // std::cout << "Hello world!";
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        string s;
        cin>>s;
        int ans0=0,ans1=0;
                for(int i=0;i<n;i++){
                    if(s[i]=='0'){
                        ans0=Xor(ans0,a[i]);
                    }
                    else{
                        ans1=Xor(ans1,a[i]);
                    }
                }
                
        int q;
        cin>>q;
        // int temp=q;
        while(q--){
            int tp;
            cin>>tp;
            if(tp==1){
                int l,r;
                cin>>l>>r;
                for(int i=l-1;i<r;i++){
                    ans0=Xor(ans0,a[i]);
                    ans1=Xor(ans1,a[i]);
                }
            }
            else{
                char g;
                cin>>g;
                if(g=='0'){
                    cout<<ans0<<" ";
                }
                else{
                    cout<<ans1<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
