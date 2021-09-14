/*
    DSA Foundations - Graphs                                                              Date: 20-Dec-2020

1. You are given a 2d array where 0's represent land and 1's represent water. 
   Assume every cell is linked to it's north, east, west and south cell.
2. You are required to find and count the number of islands.
*/       
import java.io.*;

public class count_islands {
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

      int m = Integer.parseInt(br.readLine());
      int n = Integer.parseInt(br.readLine());
      int[][] arr = new int[m][n];

      for (int i = 0; i < m; i++) {
         String parts = br.readLine();
         for (int j = 0; j < n; j++) {
            arr[i][j] = Integer.parseInt(parts.split(" ")[j]);
         }
      }

      boolean visited[][] = new boolean[m][n];
      int count = 0;
    
      for(int i = 0; i< m; i++) {
          for(int j = 0; j < n; j++) {
              if(arr[i][j] == 0 && visited[i][j] == false) {
                  calComponent(arr, i, j, visited);
                  count++;
              }
          }
      }
      
      System.out.println(count);
   }
   
    //    0 -> land
    //    1 -> water
    // we have to count the number of islands the connected components of zeros
   
   public static void calComponent(int[][] arr, int i, int j, boolean[][] visited) {
       // strong or smart base case
       if(i < 0 || j < 0 || i >= arr.length || j >= arr[0].length || visited[i][j] == true || arr[i][j] == 1)
         return;
       
       visited[i][j] = true;
       
       // reactive calls - without looking at possible conditions or calls to which base case has to react
       calComponent(arr, i + 1, j, visited); // south
       calComponent(arr, i - 1, j, visited); // north
       calComponent(arr, i, j + 1, visited); // east
       calComponent(arr, i, j - 1, visited); // west
   }

}