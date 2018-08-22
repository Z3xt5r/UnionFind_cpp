#include <iostream>

using namespace std;
int *id = NULL;
int N;
int *sz = NULL;

void Create() {
    cout<<"Enter size : ";
    cin>>N;
    id = new int[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }
    for (int i = 0; i < N; i++) {
        sz[i] = 1;
    }

}

class QuickFind {

public:


    bool connected(int p, int q) {
        return id[p] == id[q];
    }

    void Union(int p, int q) {
        int pid = id[p];
        int qid = id[q];
        for (int i = 0; i < N; i++) {
            if (id[i] == pid)
                id[i] = qid;
        }
    }

};

class QuickUnion {
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];  //Path compression
            i = id[i];
        }
        return i;
    }

public:
    bool connected(int p, int q) {
        return root(p) == root(q);
    }

    void Union(int p, int q) {

        int i = root(p);
        int j = root(q);
        id[i]=j;
//        if (sz[i] < sz[j]) {
//            id[i] = j;
//           sz[j] += sz[i];
//        } else {
//            id[j] = i;
//            sz[i] += sz[j];
//        }

    }
};

int main() {
    int x;
    int p,q1;

   Create();
    cout<<"1. QuickFind \n";
    cout<<"2. QuickUnion\n";
    cout<<"Response : ";
    cin>>x;
    if(x==1)
    {
        while(1){
    QuickFind q;
    cout<<"1. Union \n 2. Connected \n 3. Exit";
        cin>>x;
        if(x==1){
            cout<<"Enter Elements : ";
            cin>>p;
            cin>>q1;
            q.Union(p,q1);}
            else if(x==2)
        {
            cout<<"Enter Elements : ";
            cin>>p>>q1;
            q.connected(p,q1);
        }

        else
            break;}


    }
    else
    {

        while(1){
            QuickUnion q;
            cout<<"1. Union \n";
            cout<<"2. Connected \n";
            cout<<"3. Exit";
            cin>>x;
            if(x==1){
                cout<<"Enter Elements : ";
                cin>>p;
                cin>>q1;
                q.Union(p,q1);}
            else if(x==2)
            {
                cout<<"Enter Elements : ";
                cin>>p>>q1;
                if(q.connected(p,q1))
                    cout<<"Connected";
                else
                    cout<<"Not Connected";
            }

            else
                break;}

    }
}