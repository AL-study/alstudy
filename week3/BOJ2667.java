package ex01;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
 
public class BOJ2667 {
    public static int SIZE;
    public static int[][] danji;
    public static boolean[][] visited;
    
    public static PriorityQueue<Integer> pq;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        SIZE = Integer.parseInt(br.readLine());
        
        danji = new int[SIZE][SIZE];
        visited = new boolean[SIZE][SIZE];
        
        pq = new PriorityQueue<Integer>();
        
        for(int i=0; i < SIZE; i++) {
            String str = br.readLine();
            for(int j=0; j < SIZE; j++) {
                danji[i][j] = Integer.parseInt(str.substring(j, j+1));
            }
        }
        
        // danji�� ��ȸ�ϸ鼭 1�̰� �湮 ����� ���� ��ǥ�� ���ο� ������ ���� ��
        for(int i=0; i < SIZE; i++) {
            for(int j=0; j < SIZE; j++) {
                if(danji[i][j] == 1 && !visited[i][j]) BFS(i, j);
            }
        }
        // ť�� ����� ������ ���̴�.
        System.out.println(pq.size());
        
        // �켱���� ť�� ���� ������ �켱������ ������ ������ ť�� �������� ���� ����ϸ� �ȴ�.
        while(!pq.isEmpty()) {
            System.out.println(pq.poll());
        }
    }
    
    public static void BFS(int y, int x) {
        Queue<int[]> queue = new LinkedList<int[]>();
        queue.offer(new int[] {y, x});
        
        int count = 0;
        while(!queue.isEmpty()) {
            int currY = queue.peek()[0];
            int currX = queue.peek()[1];
            queue.poll();
            
            // ��ǥ ������ �ʰ��ߴ��� Ȯ���Ѵ�.
            if(currY < 0 || currX < 0 || currY >= SIZE || currX >= SIZE) continue;
            // �ش� ��ǥ�� 0 �̸� �����ϸ� �ȵȴ�.
            if(danji[currY][currX] == 0) continue;
 
            // �湮 �̷��� �ִ��� Ȯ���Ѵ�.
            if(visited[currY][currX]) continue;
            // �湮 �̷��� ����� ī��Ʈ�� 1 ���� ��Ų��.
            count += 1;
            visited[currY][currX] = true;
            
            // ��ó ���� �¿� ��ǥ�� ť�� �Է��Ѵ�. 
            queue.offer(new int[] {currY+1, currX});
            queue.offer(new int[] {currY-1, currX});
            queue.offer(new int[] {currY, currX+1});
            queue.offer(new int[] {currY, currX-1});
        }
        // ���� ������ ���� �켱���� ť�� �����Ѵ�.
        pq.offer(count);
    }
 
}