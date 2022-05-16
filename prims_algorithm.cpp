#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edg;
class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }
};
class adjacency_list
{
public:
    node *head;

    adjacency_list()
    {
        head = NULL;
    }
    void insert(int d)
    {
        node *n = new node();
        n->data = d;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }
    void print()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            node *ptr = head;
            while (ptr != NULL)
            {
                cout << ptr->data << "-------";
                ptr = ptr->next;
            }
        }
    }
};
void prim(adjacency_list *obj[], vector<vector<int>> ew, int vertex)
{
    int parent[vertex];
    int visit[vertex];
    int distance[vertex];
    for (int i = 0; i < vertex; i++)
    {
        parent[i] = -1;
        visit[i] = 0;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    priority_queue<edg, vector<edg>, greater<edg>> pt;
    pt.push(make_pair(distance[obj[0]->head->data], obj[0]->head->data));
    while (pt.empty() == false)
    {
        node *ptr = obj[pt.top().second]->head;
        pt.pop();
        if (parent[ptr->data] != -1 && visit[ptr->data] == 0)
        {
            cout<<parent[ptr->data]<<"<-->"<<ptr->data<<endl;
        }
        visit[ptr->data] = 1;
        node *ptr2 = ptr->next;
        while (ptr2 != NULL)
        {
            if (visit[ptr2->data] == 0)
            {
                if(ew[ptr->data][ptr2->data] < distance[ptr2->data])
                {
                    parent[ptr2->data] = ptr->data;    
                    distance[ptr2->data] = ew[ptr->data][ptr2->data];
                }
                pt.push(make_pair(distance[ptr2->data], ptr2->data));                
            }
            ptr2 = ptr2->next;
        }
         
    }
}
int main()
{
    int vertex, edge, v1, v2, tew;
    cout << "enter total vertices: ";
    cin >> vertex;
    cout << "enter total edges: "<<endl;
    cin >> edge;
    vector<vector<int>> edge_weight;
    adjacency_list *obj[vertex];
    for (int i = 0; i < vertex; i++)
    {
        obj[i] = new adjacency_list();
        obj[i]->insert(i);
        vector<int> temp;
        for (int j = 0; j < vertex; j++)
        {
            temp.push_back(0);
        }
        edge_weight.push_back(temp);
    }
    cout<<"enter vertex 1, vertex 2 and edge weight in single line eg. 1 2 10"<<endl;
    for (int i = 0; i < edge; i++)
    {
        //cout << " enter vertex 1: ";
        cin >> v1;
        //cout << " enter vertex 2: ";
        cin >> v2;
        int ew;
       // cout << " enter edge weight: ";
        cin>>ew;
        obj[v1]->insert(v2);
        obj[v2]->insert(v1);
        edge_weight[v1][v2] = ew;
        edge_weight[v2][v1] = ew;
        tew += ew;
    }
    prim(obj,edge_weight,vertex);
    return 0;
}
