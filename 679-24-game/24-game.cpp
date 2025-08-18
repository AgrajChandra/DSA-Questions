class rational{
    int p, q;
public:
    rational(): p(0), q(1){}
    rational(int x): p(x), q(1){}
    rational(int p, int q): p(p), q(q){
        if (q==0) throw invalid_argument("denominator is 0");
    }
    rational operator+(const rational& other) const {
        return rational(p*other.q+other.p*q, q*other.q);
    }
    rational operator-(const rational& other) const {
        return rational(p*other.q-other.p*q, q*other.q);
    }
    rational operator*(const rational& other) const {
        return rational(p*other.p, q*other.q);
    }
    rational operator/(const rational& other) const {
        return rational(p*other.q, q*other.p);
    }
    bool operator==(const int x){
        reduced();
        return p==x && q==1;
    }
    void reduced(){
        if (p==0) { q=1; return;}
        int g=gcd(p, q);
        if (q<0)  p=-p, q=-q; 
        p/=g, q/=g;
    }
    void print(){
        cout<<p<<"/"<<q<<"\n";
    }
};
char op[5]="+-*/";
array<array<int, 3>, 5> pos{{
    {2, 4, 6}, {3, 5, 6}, {2,  5, 6},
    {4, 5, 6}, {3, 4, 6}}};
constexpr int INF=1e6+3;
class Solution {
public:
    static rational postfix(const string& s){
        vector<rational> st;
        for(char c: s){
            if (isdigit(c)) 
                st.push_back(rational(c-'0'));  // number
            else {
                rational y=st.back(); st.pop_back();
                rational x=st.back(); 
                switch(c){
                    case '+': st.back()=x+y; break;
                    case '-': st.back()=x-y; break;
                    case '*': st.back()=x*y; break;
                    case '/': 
                    if (y==0) return rational(INF);// divide by 0
                    st.back()=x/y;
                }
            }
        }
    //    st.back().print();
        return st.back();
    }

    static bool get24(int x[4]){
        for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        for(int k=0; k<4; k++){
            char ops3[3] = {op[i], op[j], op[k]};
            for(const auto& p : pos){
                string s(7, '?');
                for(int u=0, v=0, sz=0; sz<7; sz++){
                    if (sz==p[v]) s[sz]=ops3[v++]; // place operator
                    else  s[sz]='0'+x[u++]; // place digit
                }
            //    cout<<s<<"->";
                if (postfix(s)==24) return 1;
            }
        }
        return 0;
    }
    static bool judgePoint24(vector<int>& cards) {
        int a, b, c, d;
        bitset<10000> seen=0;
        int cnt=0, x=0;
        for(int i=0; i<4; i++){
            a=cards[i];
            for(int j=0; j<4; j++){
                if (i==j) continue;
                b=cards[j];
                for(int k=0; k<4; k++){
                    if(k==i ||k==j) continue;
                    c=cards[k];
                    for(int l=0; l<4; l++){
                        if (l==i || l==j || l==k) continue;
                        d=cards[l];
                        x=1000*a+100*b+10*c+d;
                        if (seen[x]) continue;
                    //    cout<<x<<":"<<cnt++<<"\n----\n";
                        seen[x]=1;
                        int arr[4]={a, b, c, d};
                        if (get24(arr)) return 1;
                    }
                }
            }
        }
        return 0;
    }
};