package ex01;



	import java.util.HashSet;
	import java.util.Scanner;
	 
	public class ex10815 {
	 
	    public static void main(String[] args) throws Exception {
	        // TODO Auto-generated method stub
	       
	         Scanner sc = new Scanner(System.in);
	        int N = sc.nextInt();
	        HashSet<Integer> set = new HashSet<Integer>();
	        for (int i = 0; i < N; i++) {
	            set.add(sc.nextInt());
	        }
	 
	        int M = sc.nextInt();
	        for (int i = 0; i < M; i++) {
	            if (set.contains(sc.nextInt())) {
	                System.out.print(1);
	            } else {
	                System.out.print(0);
	            }
	            System.out.print(" ");
	        }
	    }
	 
	}