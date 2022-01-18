import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj9012 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            Stack<Character> stack = new Stack<>();
            String str = br.readLine();
            boolean flag = false;

            for (int i = 0; i < str.length(); i++) {
                char ch = str.charAt(i);

                if (ch == '(') {
                    stack.push(ch);
                } else if (ch == ')') {
                    if (!stack.isEmpty()) {
                        stack.pop();
                    } else {
                        flag = true;
                        break;
                    }
                }
            }
            if (stack.isEmpty() && !flag) {
                sb.append("YES").append("\n");
            } else {
                sb.append("NO").append("\n");
            }
        }

        System.out.println(sb);
    }
}
