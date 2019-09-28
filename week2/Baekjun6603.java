package ex01;
import java.util.*;

public class Baekjun6603 {
 // 백트랙킹 을 이용한 문제 

	static int K;
	static int []iArr;
	static int count;
	static StringBuffer sb = new StringBuffer();
	
	
	static void dfsForRecursive(int v, String str) {
		if(count == 6) {
			sb.append(str+"\n");
		}else {
			for(int i =v+1; i < K; i++) {
				++count;
				dfsForRecursive(i, str+iArr[i]+" ");
			}
		}
		--count;
	}
	
	
	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);
		
		while(( K = sc.nextInt())!=0) {
			iArr = new int[K];
			for(int i = 0; i< K; i++) {
				iArr[i] =sc.nextInt();
			}
			for(int i = 0; i < K; i++) {
				count = 1;
				dfsForRecursive(i, iArr[i]+" ");
			}
			sb.append("\n");	
		}
		System.out.println(sb.toString());                
		
	}
}
