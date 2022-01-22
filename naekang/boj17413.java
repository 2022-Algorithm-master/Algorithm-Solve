import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class boj17413 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        String S = br.readLine();

        Stack<Character> stack = new Stack<>();
        boolean checkIsIn = false;

        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '<') {
                checkIsIn = true;

                while (!stack.isEmpty()) {
                    sb.append(stack.pop());
                }
                sb.append(S.charAt(i));
            } else if (S.charAt(i) == '>') {
                checkIsIn = false;
                sb.append(S.charAt(i));
            } else if (checkIsIn) {
                sb.append(S.charAt(i));
            } else if (!checkIsIn) {
                if (S.charAt(i) == ' ') {
                    while (!stack.isEmpty()) {
                        sb.append(stack.pop());
                    }
                    sb.append(S.charAt(i));
                } else {
                    stack.push(S.charAt(i));
                }
            }
        }

        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }

        System.out.println(sb);
    }
}
