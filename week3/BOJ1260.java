package ex01;

import java.util.*;
public class BOJ1260 {
    static int N,V;
    static int visit[],arr[][];
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        N=sc.nextInt();
        int M=sc.nextInt();
        V=sc.nextInt();
        arr=new int[N+1][N+1];
         
        for(int i=1;i<=M;i++){
            int x=sc.nextInt();
            int y=sc.nextInt();
             
            arr[x][y]=1;
            arr[y][x]=1;
        }
        visit=new int[N+1];
        DFS(V);
        System.out.println();
        visit=new int[N+1];
        BFS();
        System.out.println();
 
    }
     
    static void DFS(int x){
        visit[x]=1;
        System.out.print(x + " ");
        for(int i=1;i<=N;i++){
            if(arr[x][i]== 1 && visit[i]==0)
                DFS(i);
        }
    }
     
    static void BFS(){
        Queue<Integer> q = new LinkedList<Integer>();
        visit[V]=1;
        q.add(V);
        while(!q.isEmpty()){
            int x = q.peek();
            q.poll();
            System.out.print(x + " ");
            for(int i=1;i<=N;i++){
                if(arr[x][i]==1 && visit[i]==0){
                    visit[i]=1;
                    q.add(i);
                }
            }
        }
    }
 
}

