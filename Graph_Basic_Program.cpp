# include <bits/stdc++.h>
using namespace std;
# include <vector>
# define vi vector<int>
# define vvi vector<vi>
# define iter vector<int> :: iterator 
const int N = 1e5+2;
vi adjl[N];
void BFS(bool vis[])
{
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        iter it;
        for(it=adjl[node].begin();it!=adjl[node].end();it++)
        {
            if(!vis[*it])
            {
                q.push(*it);
                vis[*it]=1;
            }
        }
        
    }
    
}
void DFS(stack<int> st,bool vis[])
{
    int node = st.top();
    st.pop();
    cout<<node<<" ";
    iter it;
    for(it=adjl[node].begin();it!=adjl[node].end();it++)
    {
        if(!vis[*it])
        { 
            st.push(*it);
            vis[*it]=1;
            DFS(st,vis);
        }
    }
    
}
int main()
{
    /*Graph can be code in two ways :- 1) Adjancecny Matrix  2) Adjancency List
    1) Adjancency Matrix
    */ 
    int n,m;
    cin>>n>>m;
    vvi adjM(n+1,vi(n+1,0));
    cout<<"Adjancency Matrix"<<endl;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adjM[x][y]=1;
        adjM[y][x]=1;
    }
    // code for adjancency matrix lets check wheather it is working or not
    for(int i=1;i<n+1;i++)
    { 
       for(int j=1;j<n+1;j++)
       {
           cout<<adjM[i][j]<<" ";
       }cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"Adjancency List"<<endl;
    /* Working fine we use the input as 7 7
       (1 ,2)      Output:- [0 1 1 0 0 0 0 
       (1, 3)                1 0 0 1 1 1 1 
       (2, 4)                1 0 0 0 0 0 1 
       (2, 5)                0 1 0 0 0 0 0 
       (2, 6)                0 1 0 0 0 0 0 
       (2, 7)                0 1 0 0 0 0 0 
       (3 ,7)                0 1 1 0 0 0 0]
       These Represent edges from One Node to Another; */
    
    // 2) Adjancency List
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }
    /*
    Input remain same as above output should be Like This 
    1->2 3 
    2->1 4 5 6 7 
    3->1 7 
    4->2 
    5->2 
    6->2 
    7->2 3
    */
    for(int i=1;i<n+1;i++)
    {
        cout<<i<<"->";
        vector <int> :: iterator it;
        for(it=adjl[i].begin();it!=adjl[i].end();it++)
        {
            cout<<*it<<" ";
        }cout<<endl;
    }
    bool vis[n];
    for(int i=1;i<n+1;i++)
    {
        vis[i]=0;
    }
    cout<<endl<<endl;
    cout<<"Breadth First Search"<<endl;
    BFS(vis);
    for(int i=1;i<n+1;i++)
    {
        vis[i]=0;
    }
    stack <int> st;
    st.push(1);
    vis[1]=1;
    cout<<endl<<endl;
    cout<<"Depth First Search"<<endl;
    DFS(st,vis);

}