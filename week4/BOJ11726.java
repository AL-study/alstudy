package ex01;
import java.util.*;
public class BOJ11726 {

	public static void main(String[] args) {
	
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int arr [] = new int[1002];
		
		arr[0] = 1; // 2 * 1 사이즈
		arr[1] = 2; // 2 * 2 사이즈
		for (int i = 2; i < n; i++) {
			arr[i] = (arr[i-1] + arr[i-2])%10007;
		}
		System.out.println(arr[n-1]);
	}

}
