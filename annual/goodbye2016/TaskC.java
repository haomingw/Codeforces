package main;

import lib.InputReader;
import java.io.PrintWriter;

public class TaskC {
    static final int INF = (int) 1e9;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int min = -INF, max = INF;
        int n = in.nextInt();
        int delta = 0;
        for (int i = 0; i < n; i++) {
            int c = in.nextInt(), d = in.nextInt();
            if (d == 1) {
                min = Math.max(min, 1900 - delta);
            } else {
                max = Math.min(max, 1899 - delta);
            }
            delta += c;
        }
        if (min > max) {
            out.println("Impossible");
        } else if (max == INF) {
            out.println("Infinity");
        } else {
            out.println(max + delta);
        }
    }
}
