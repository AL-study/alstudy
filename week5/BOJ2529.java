package ex01;

import java.util.*;
public class BOJ2529 {

	static int k;
	static String[] arr;
		
	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);
		k = sc.nextInt();
		sc.nextLine();
		
		arr = sc.nextLine().split(" ");
		visited = new boolean[10];
		result = new ArrayList<>();
		for(int i = 0; i < 10; i++) {
			visited[i] = true;
			solve(0,i,String.valueOf(i));
		}
		System.out.println(result.get(result.size()-1));
		System.out.println(result.get(0));
		
	}
		static boolean [] visited;
		static List<String> result;
		
		private static void solve(int cnt, int left, String t) {
			if(cnt == k) {
				result.add(t);
				visited[left] = false;
				return;
			}
			for(int i = 0; i < 10; i++) {
				if(visited[i])
					continue;
				if(left == i)
					continue;
				if(arr[cnt].equals(">"))
				{
				if(left<i)
					continue;
				}else if(left > i)
					continue;
					visited[i] = true;
					solve(cnt+1,i,t+i);					
				}
				visited[left] = false;
			}
		}

