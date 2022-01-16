import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj1158 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());

    Queue<Integer> queue = new LinkedList<>();

    // 1부터 N까지의 숫자를 queue에 삽입
    for (int i = 1; i <= N; i++) {
      queue.add(i);
    }

    sb.append("<");

    // queue의 크기가 1이될때까지 반복
    while (queue.size() != 1) {
      // K - 1번째까지 queue 앞에서 꺼내서 뒤로 넣기
      for (int i = 0; i < K - 1; i++) {
        queue.add(queue.poll());
      }
      sb.append(queue.poll()).append(", ");
    }
    // 큐의 마지막에 남은 숫자를 꺼낸다
    sb.append(queue.poll()).append(">");

    System.out.println(sb);
  }
}
