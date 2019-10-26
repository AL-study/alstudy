package ex01;

import java.io.FileInputStream;
import java.util.*;
import java.util.stream.*;
 
//1. 제일 큰 값 (동전) 으로 부터 입력 받은 값과 비교하여 입력받은 값이 크면 나눈다.
//
//나눈 값은 동전의 개수가 되며 나머지는 그 다음 다른 돈으로 바꿀 돈이 된다.
//
//2. 돈이 0이 될때까지 반복한다.

class BOJ11407 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(new FileInputStream("input.txt"));
        // Scanner sc = new Scanner(System.in);
 
        int N = sc.nextInt();
        int M = sc.nextInt();
        int count =0;
        int[] arr=  new int[N];
        for(int i=0; i<N; i++){
            arr[i] = sc.nextInt();
        }
        
            for(int i = N-1; i>=0; i--){
                if(M>=arr[i]){
                    count += M/arr[i];
                    M = M%arr[i];
                }
                
            }
            
            System.out.println(count);
        
        
    }
 
}
