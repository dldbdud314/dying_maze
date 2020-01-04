//DFSMatrix.h

#ifndef DFSMATRIX_H
#define DFSMATRIX_H
#define MAX_STACK_SIZE 100

class DFSMatrix{

protected:
   int m, n; //dfs_map의 가로 세로
   int** dfs_map; //input 받아오는 미로 matrix
    
public:      
   struct XY{
       int a;
       int b;
    }; //지나온 경로 (a, b) 저장하는 구조체
    struct XY stPath[MAX_STACK_SIZE]; //최단경로 (a, b) 저장용 구조체(historyXY)의 배열(stPath)
    int q; //최단경로 (a, b) 저장용 구조체(historyXY) 배열(stPath)의 index
    DFSMatrix();
    ~DFSMatrix();
    void setDFSMatrix();
    void dfs(int tr, int tc, int d);
};

#endif
