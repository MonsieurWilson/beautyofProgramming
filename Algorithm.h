#ifndef ALGORITHM 
#define ALGORITHM 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>


using namespace std; 


class Algorithm{
public:
    // DP
    // Quick Sort
    void quickSort(int A[], int beg, int end) {
        // End points to the next of the array's edge.
        if (beg < end - 1) {
            int mid = hoarePartition(A, beg, end); 
            quickSort(A, beg, mid); 
            quickSort(A, mid + 1, end); 
        }
    }
    int partition(int A[], int beg, int end) {
        int pivot = A[end - 1]; 
        int i = beg - 1; 
        // Let i + 1 points to the first element that is bigger than pivot.
        // After scanning the array, we should swap the A[i + 1] and pivot.
        // Initializing the i to be beg - 1 is just to overcome the case that the pivot's position is beg.
        for (int j = beg; j != end - 1; ++j) {
            if (A[j] < pivot) {
                ++i; 
                swap(A[j], A[i]); 
            }
        }
        ++i; 
        swap(A[i], A[end - 1]); 

        return i; 
    }
    // Partition based on the random pivot
    int randomPartition(int A[], int beg, int end) {
        srand((unsigned)time(NULL)); 
        int randPivot = rand() % (end - beg) + beg; 
        swap(A[randPivot], A[end-1]); 
        return partition(A, beg, end); 
    }
    // Partition base on hoare algorithm.
    int hoarePartition(int A[], int beg, int end) {
        int i = beg, j = end; 
        // Let the beg to be the pivot.
        int pivot = A[beg]; 
        while (true) {
            while (A[++i] < pivot && i < end); 
            while (A[--j] > pivot); 
            if (i >= j) {
                break; 
            }
            swap(A[i], A[j]); 
        }
        swap(A[j], A[beg]);
        return j; 
    }

    // Merge Sort
   void mergeSort(int A[], int beg, int end) {
        if (beg < end - 1) {
            int mid = (beg + end - 1) / 2; 
            mergeSort(A, beg, mid + 1); 
            mergeSort(A, mid + 1, end); 
            merge(A, beg, mid, end); 
        }
    }
    void merge(int A[], int beg, int mid, int end) {
        int n1 = mid - beg + 1, n2 = end - 1 - mid; 
        int *p1 = new int[n1], *p2 = new int[n2]; 
        for (int i = 1; i <= n1; ++i) {
            p1[i - 1] = A[beg + i - 1]; 
        }
        for (int j = 1; j <= n2; ++j) {
            p2[j - 1] = A[mid + j]; 
        }
        for (int i = 1, j = 1, k = beg; k != end; ++k) {
            if (i > n1 || (j <= n2 && p1[i - 1] > p2[j - 1])) {
                A[k] = p2[j - 1]; 
                ++j; 
            }
            else /*if (j > n2 || (i <= n1 && p2[j - 1] >= p1[i - 1]))*/{
                A[k] = p1[i - 1]; 
                ++i; 
            }
        }
        delete [] p1; 
        delete [] p2; 
    }
    
    // Max Subarray
    int findMaxSubarray(int A[], int beg, int end, int &maxLeft, int &maxRight) {
        if (end - 1 == beg) {
            maxLeft = maxRight = beg;  
            return A[beg]; 
        }
        int mid = (end + beg - 1) / 2; 
        int leftBeg,leftEnd,leftMax = findMaxSubarray(A, beg, mid + 1, leftBeg, leftEnd); 
        int rightBeg,rightEnd,rightMax = findMaxSubarray(A, mid+1, end, rightBeg, rightEnd); 
        int crossBeg,crossEnd,crossMax = maxCrossingSubarray(A, beg, mid, end, crossBeg, crossEnd); 
        if (leftMax >= rightMax && leftMax >= crossMax) {
            maxLeft = leftBeg; 
            maxRight = leftEnd; 
            return leftMax; 

        }
        else if (rightMax > leftMax && rightMax > crossMax) {
            maxLeft = rightBeg; 
            maxRight = rightEnd; 
            return rightMax; 
        }
        else {
            maxLeft = crossBeg; 
            maxRight = crossEnd; 
            return crossMax; 
        }
    }
    int maxCrossingSubarray(int A[], int beg, int mid, int end, int &maxLeft, int &maxRight) {
        int leftSum = A[mid], rightSum = A[mid + 1]; 
        maxLeft = mid; 
        maxRight = mid + 1; 
        for (int i = mid - 1, sum = leftSum; i >= beg; --i) {
            sum += A[i]; 
            if (sum > leftSum) {
                leftSum = sum; 
                maxLeft = i; 
            }
        }
        for (int i = mid + 2,sum = rightSum; i != end; ++i) {
            sum += A[i]; 
            if (sum > rightSum) {
                rightSum = sum; 
                maxRight = i; 
            }
        }
        return leftSum + rightSum; 
    }

    template<typename T>
    T maxSubArray(T *array, T beg, T end, int &first, int &last) {
        // DP
        T tmp = array[end - 1]; 
        T result = array[end - 1]; 
        for (int index = end - 2; index >= beg; --index) {
            if (tmp < 0) {
                tmp = 0; 
            }
            tmp += array[index]; 
            if (tmp > result) {
                result = tmp; 
                first = index; 
            }
        }

        tmp = array[beg]; 
        result = array[beg]; 
        for (int index = beg + 1; index != end; ++index) {
            if (tmp < 0) {
                tmp = 0; 
            }
            tmp += array[index]; 
            if (tmp > result) {
                result = tmp; 
                last = index; 
            }
        }
        return result; 
    }

    //------------------------------------------//
    // Matrix Chain
    template<int N>
    void matrixChain(int *p,int n,int (*m)[N],int (*s)[N]) {
        for (int i=1;  i<=n;  ++i) {
            m[i][i]=0; 
        }
        for (int r=2;  r<=n;  ++r) {
            for (int i=1;  i<=n-r+1;  ++i) {
                int j=r+i-1; 
                m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j]; // The case k = 0
                s[i][j]=i; 
                for (int k=i+1;  k<j;  ++k) {
                    int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]; 
                    if (t<m[i][j]) {
                        m[i][j]=t; 
                        s[i][j]=k; 
                    }
                }
            }
        }
    }
    // Output
    template<int N>
    void traceBack(int i,int j,int s[][N]) {
        if (i==j) {
            cout<<"A"<<i; 
        }
        else {
            cout<<"("; 
            traceBack(i, s[i][j], s); 
            traceBack(s[i][j]+1, j, s); 
            cout<<")"; 
        }
    }
    //-------------------------------------------//
    // Length of the Increasing Subsequence
    // <Beauty of Programming>
    int LISLength(const int *array, const int &size) {
        // O(n^2)
        int *lis = new int[size]; 
        for (int i = 0; i != size; ++i) {
            lis[i] = 1; 
            for (int k = 0; k != i; ++k) {
                if (array[i] > array[k] && lis[k] + 1 > lis[i]) {
                    lis[i] = lis[k] + 1; 
                }
            }
        }

        int max = INT_MIN; 
        for (int idx = 0; idx != size; ++idx) {
            if (max < lis[idx]) {
                max = lis[idx]; 
            }
        }

        return max; 
    }

    int improvedLISLength(const int *array, const int &size) {
        // Using binarySearch
        int *lis = new int[size]; 
        int *maxV = new int[size + 1]; 
        maxV[0] = minElement(array, 0, size) - 1; 
        maxV[1] = array[0]; 
        int maxLength = 1; 
        
        for (int idx1 = 0; idx1 != size; ++idx1) {
            lis[idx1] = 1; 
            /*
            int idx2; 
            for (idx2 = maxLength; idx2 >= 0; --idx2) {
                if (array[idx1] > maxV[idx2]) {
                    lis[idx1] = idx2 + 1; 
                    break; 
                }
            }
            */  
            int idx2; 
            binarySearch(maxV, 0, maxLength + 1, array[idx1], idx2); 
            lis[idx1] = idx2 + 1; 
            
            if (lis[idx1] > maxLength) {
                maxLength = lis[idx1]; 
                maxV[lis[idx1]] = array[idx1]; 
            }
            else if (maxV[idx2 + 1] > array[idx1]) {
                maxV[idx2 + 1] = array[idx1]; 
            }
        }

        return maxLength; 
    }
    int minElement(const int *array, const int &beg, const int &end) {
        int min = INT_MAX; 
        for (int idx = beg; idx != end; ++idx) {
            if (array[idx] < min) {
                min = array[idx]; 
            }
        }

        return min; 
    }
    void binarySearch(const int *array, const int &beg, const int &end, const int &key, int &pos) {
        // Return the last ele's index which is smaller than key.
        int start = beg, last = end - 1; 
        if (key > array[last]) {
            pos = last; 
            return; 
        }
        if (key < array[start]) {
            pos = start - 1; 
            return; 
        }
        while (start <= last) {
            int mid = (start + last) / 2; 
            if (array[mid] < key) {
                start = mid + 1; 
            }
            else {
                last = mid - 1; 
            }
        }
        pos = last; 
    }

    // Length of the Common Subsequence
    template <int ysize>
    int LCSLength(int m, int n, char *x, char *y, int (*c)[ysize], int (*b)[ysize]) {
        int i, j; 
        for (i = 1; i <= m; ++i) {
            c[i][0] = 0; 
        }
        for (j = 0; j <= n; ++j) {
            c[0][j] = 0; 
        }
        for (i = 1; i <= m; ++i) {
            for (j = 1; j <= n; ++j) {
                if (x[i] == y[j]) {
                    c[i][j] = c[i - 1][j - 1] + 1; 
                    b[i][j] = 1; 
                }
                else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j]; 
                    b[i][j] = 2; 
                }
                else {
                    c[i][j] = c[i][j - 1]; 
                    b[i][j] = 3; 
                }
            }
        }

        return c[m][n]; 
    }
    template <int ysize>
    void LCS(int i, int j, char *x, int (*b)[ysize]) {
        if (i == 0 || j == 0) {
            return; 
        }
        if (b[i][j] == 1) {
            LCS(i - 1, j - 1, x, b); 
            cout<<x[i]<<' '; 
        }
        else if (b[i][j] == 2) {
            LCS(i - 1, j, x, b); 
        }
        else {
            LCS(i, j - 1, x, b); 
        }
    }
    // Cut Rod
    int cutRod(int *p,int n,int *s) {
        int r[n+1]; 
        r[0]=0; 
        if (n==0) {
            return r[0]; 
        }
        for (int i=1;  i<=n;  ++i) {
            int sum=-32768; 
            for (int j=1;  j<=i;  ++j) {
                int temp=p[j-1]+r[i-j]; 
                if (temp>sum) {
                    sum=temp; 
                    s[i]=j; 
                }
            }
            r[i]=sum; 
        }
        return r[n]; 
    }
    void cutSolution(int *s,int n) {
        while (n>0) {
            cout<<s[n]<<' '; 
            n=n-s[n]; 
        }
    }

    // 0-1 KnapSack
    template<int csize>
    void knapSack(int v[],int w[],int c,int n,int (*m)[csize]) {
        int jMax=min(w[n]-1, c); 
        for (int j=0;  j<=jMax;  ++j) {
            m[n][j]=0; 
        }
        for (int j=w[n];  j<=c ;  ++j) {
            m[n][j]=v[n]; 
        }
        for (int i=n-1;  i>1;  --i) {
            jMax=min(w[i]-1,c); 
            for (int j=0;  j<=jMax;  ++j) {
                m[i][j]=m[i+1][j]; 
            }
            for (int j=w[i];  j<=c;  ++j) {
                m[i][j]=max(m[i+1][j-w[i]]+v[i] , m[i+1][j]); 
            }
            m[1][c]=m[2][c]; 
            if (c>=w[1]) {
                m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]); 
            }
        }
    }
    // Fomular the solution
    template<int csize>
    void traceBack(int (*m)[csize],int w[],int c,int n,int x[]) {
        for (int i=1;  i!=n;  ++i) {
            if (m[i][c]==m[i+1][c]) {
                x[i]=0; 
            }
            else {
                x[i]=1; 
                c-=w[i]; 
            }
        }
        if (m[n][c]) {
            x[n]=1; 
        }
        else {
            x[n]=0; 
        }
    }

    // Greedy
    //活动选择问题
    void greedySelector(int n,int s[],int f[],int A[]) {
        A[1]=1; 
        int j=1; 
        for (int i=2;  i<=n;  ++i) {
            if (s[i]>=f[j]) {
                A[i]=1; 
                j=i; 
            }
            else {
                A[i]=0; 
            }
        }
    }
    //生成最优解
    void greedySolution(int n,int A[]) {
        for (int i=1;  i<=n;  ++i) {
            if (A[i]==1) {
                cout<<"a"<<i<<' '; 
            }
        }
    }
    //活动选择问题的动态规划算法
    template<int csize>
    void dpSelector(int n,int s[],int f[],int (*c)[csize]) {
        for (int i=0;  i<=n+1;  ++i) {
            c[i][i]=0; 
        }
        for (int i=0;  i!=n+1;  ++i) {
            c[i][i+1]=0; 
        }
        for (int i=0;  i<=n+1;  ++i) {
            //l表示活动数
            for (int l=2;  l<n;  ++l) {
                int j=i+l-1,sum=0; 
                for (int k=i;  k<=j;  ++k) {
                    int temp=c[i][k]+c[k][j]+1; 
                    if (sum<temp) {
                        sum=temp; 
                    }
                }
                c[i][j]=sum; 
            }
        }
    }
    //背包问题-贪心算法
    void greedyKnapSack(int n,float m,float v[],float w[],float x[]) {
        //单位重量价格数组
        float vpw[n+1]; 
        for (int i=1;  i<=n;  ++i) {
            vpw[i]=v[i]/w[i]; 
        }
        for (int i=1;  i<=n;  ++i) {
            x[i]=0; 
        }
        int count=0,index=0; 
        while (m>0&&count<=n) {
            index=findMax(n, vpw); 
            if (m>=w[index]) {
                x[index]=w[index]; 
            }
            else {
                x[index]=m; 
            }
            m-=w[index]; 
            vpw[index]=0; 
            ++count; 
        }
        
    }
    int findMax(int n,float vpw[]) {
        int index=1,max=vpw[1]; 
        for (int i=1;  i<=n;  ++i) {
            if (vpw[i]>max) {
                max=vpw[i]; 
                index=i; 
            }
        }
        return index; 
    }
    //Dijkstra单源最短路径算法
    template<int csize>
    void dijkstra(int n,int v,int *dist,int *prev,int (*c)[csize]) {
        bool s[n+1]; 
        for (int i=1;  i<=n;  ++i) {
            s[i]=false; 
            dist[i]=c[v][i]; 
            if (dist[i]==INT_MAX) {
                prev[i]=0; 
            }
            else {
                prev[i]=v; 
            }
        }
        s[v]=true; 
        dist[v]=0; 
        for (int i=1;  i<=n;  ++i) {
            int u=v; 
            int temp=INT_MAX; 
            for (int j=1;  j<=n;  ++j) {
                if (s[j]==false&&dist[j]<temp) {
                    temp=dist[j]; 
                    u=j; 
                }
            }
            s[u]=true; 
            for (int j=1;  j<=n;  ++j) {
                if (s[j]==false&&c[u][j]!=INT_MAX) {
                    int newDist=c[u][j]+dist[u]; 
                    if (newDist<dist[j]) {
                        dist[j]=newDist; 
                        prev[j]=u; 
                    }
                }
            }
        }
    }
    //最小生成树
    template<int csize>
    void prim(int n,int (*c)[csize]) {
        int closest[n+1],lowcost[n+1]; 
        bool s[n+1]; 
        s[1]=true; 
        for (int i=2;  i<=n;  ++i) {
            lowcost[i]=c[1][i]; 
            closest[i]=1; 
            s[i]=false; 
        }
        for (int i=1;  i<=n;  ++i) {
            int temp=INT_MAX; 
            int j=1; 
            for (int k=2;  k<=n;  ++k) {
                if (s[k]==false&&lowcost[k]<temp) {
                    temp=lowcost[k]; 
                    j=k; 
                }
            }
            s[j]=true; 
            cout<<"Route "<<j<<" -> "<<closest[j]<<endl; 
            for (int k=2;  k<=n;  ++k) {
                if (s[k]==false&&c[j][k]<lowcost[k]) {
                    lowcost[k]=c[j][k]; 
                    closest[k]=j; 
                }
            }
        }
    }
}; 

#endif 
