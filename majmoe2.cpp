#include <bits/stdc++.h>//proje payanterm pish 2022 16 june 11:58//
using namespace std;
class majmoe
{
    friend  ostream & operator <<(ostream & ostr,const majmoe &r);
    friend  istream & operator >>(istream & istr, majmoe &r);
    private:
    string a;
    public:
    majmoe operator += (const majmoe r)//tavani//
    {
        int i,j,n=r.a.length();
        int m=pow(2,n);
        cout<<"/  ";
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(i&(1<<j))//000 001 010 011 100 101 110 111//
                    cout<<a[j];
            }
            cout<<" / ";
        }
    cout<<"\n";
        return *this;        
    }     
    majmoe operator ^ (const majmoe r)//zarb dekarti//
    {
        majmoe t;
        int i,j,n=r.a.length(),m=a.length();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cout<<"{"<<a[i]<<","<<r.a[j]<<"}"<<" ";
            }
        }
    cout<<"\n";
        return t;        
    } 
    majmoe  operator + (const majmoe r)//ejtema//
    {
        majmoe t;
        t.a=a;
        int i,j,c,n=r.a.length(),m=a.length();
        for( i=0;i<n;i++)
        {
            c=0;
            for(j=0;j<m;j++)
            {   
                if(r.a[i]==a[j])
                    c++;
            }           
            if(c==0)
                t.a+=r.a[i];
        }
        return t;
    }
    majmoe operator * (const majmoe r)//eshterak//
    {
        majmoe k;
        int i,j,c,n=r.a.length(),m=a.length();  
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(r.a[i]==a[j])
                {
                    k.a+=r.a[i];
                    break;
                }
            }
        } 
        return k;        
    }
    majmoe operator - (const majmoe r)//tafazol//
    {
        majmoe k;
        int i,j,c,n=r.a.length(),m=a.length(); 
        for(int i=0;i<m;i++)
        {
            c=0;
            for(j=0;j<n;j++)
            {
                if(a[i]==r.a[j])
                    c++;
            }
            if(c==0)
            k.a+=a[i];
        }
        return k;
    } 
    majmoe operator / (const majmoe r)//zir majmoe bodan//
    {
        majmoe t;
        int i,j,c,m=a.length(),n=r.a.length(),k=0;
        for(int j=0;j<n;j++)
        {
            c=0;
            for(int i=0;i<m;i++)
            {
                if(a[i]==r.a[j])
                    c++;
            }
            if(c!=0)
                k++;
        }
        if(k==n)
            cout<<"True"<<"\n";
        else
            cout<<"False"<<"\n";
        return t;        
    } 
};
    ostream & operator <<(ostream & ostr,const majmoe &r)//amalgar jariyan khoroji//
    {
        ostr<<r.a;
        return ostr;
    }
    istream & operator >> (istream & istr,majmoe &r)//amalgar jariyan vorodi//
    {
        istr>>r.a; 
    }
int main()
{
    majmoe a,b,c;
    cout<<"\nA : "; cin>>a;
    cout<<"\nB : "; cin>>b;
    cout<<"\n";
    c=a+b;cout<<"C = A + B (ejtema) : "<<c<<"\n\n";
    c=a*b;cout<<"C = A * B (eshterak) : "<<c<<"\n\n";
    c=a-b;cout<<"C = A - B (tafazol) : "<<c<<"\n\n";
    c=b-a;cout<<"C = B - A (tafazol) : "<<c<<"\n\n";
    cout<<"C = A / B (zirmajmoe) : ";c=a/b;cout<<"\n";
    cout<<"C = B / A (zirmajmoe) : ";c=b/a;cout<<"\n";
    cout<<"C = A ^ B (dekarti A * B) : ";c=a^b;cout<<"\n";
    cout<<"C = B ^ A (dekarti B * A) : ";c=b^a;cout<<"\n";
    cout<<"A += A (tavani A) : ";a+=a;cout<<"\n";
    cout<<"B += B (tavani B) : ";b+=b;cout<<"\n";
    return 0;
}