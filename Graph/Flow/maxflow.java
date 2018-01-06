import java.io.*;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
 
 
 
public class Main{
 
 
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CustomType customType=new  CustomType();
        Task solver = new Task();
        solver.solve(1, in, out,customType);
        out.close();
    }
 
 
    static class Task{
        public void solve(int testNumber, InputReader in, PrintWriter out,CustomType m) {
 
 
            int t=in.nextInt(),cs=1;
            while (t--!=0)
            {
                int n=in.nextInt();
 
                EdmondsKarp ff=new EdmondsKarp(n);
 
 
                int s=in.nextInt(),end=in.nextInt(),c=in.nextInt();
                for (int i=0;i<c;i++)
                {
                    int x=in.nextInt(),y=in.nextInt();
                    long z=in.nextLong();
                    ff.addEdge(x-1,y-1,z);
                    ff.addEdge(y-1,x-1,z);
                }
 
                out.printf("Case %d: %d\n",cs++,ff.getMaxFlow(s-1,end-1));
 
 
            }
 
 
 
        }
    }
 
 
 
 
 
 
 
 
 
    static class EdmondsKarp {
 
        private long[][] flow;
        private long[][] capacity;
        private int[] parent;
        private boolean[] visited;
        private int n;
        EdmondsKarp(int numOfVerticles) {
            this.n = numOfVerticles;
            this.flow = new long[n][n];
            this.capacity = new long[n][n];
            this.parent = new int[n];
            this.visited = new boolean[n];
        }
 
        public void addEdge(int from, int to, long capacity) {
            assert capacity >= 0;
            this.capacity[from][to] += capacity;
        }
 
        public long getMaxFlow(int s, int t) {
            while (true) {
                final Queue<Integer> Q = new LinkedList<>();
                Arrays.fill(visited,false);
                Q.add(s);
                visited[s] = true;
 
                boolean check = false;
                int current;
                while (!Q.isEmpty()) {
                    current = Q.poll();
                    if (current == t) {
                        check = true;
                        break;
                    }
                    for (int i = 0; i < n; ++i) {
                        if (!visited[i] && capacity[current][i] > flow[current][i]) {
                            visited[i] = true;
                            Q.add(i);
                            parent[i] = current;
                        }
                    }
                }
                if (check == false)
                    break;
 
                long temp = capacity[parent[t]][t] - flow[parent[t]][t];
                for (int i = t; i != s; i = parent[i])
                    temp = Math.min(temp, (capacity[parent[i]][i] - flow[parent[i]][i]));
 
                for (int i = t; i != s; i = parent[i]) {
                    flow[parent[i]][i] += temp;
                    flow[i][parent[i]] -= temp;
                }
            }
 
            long result = 0;
            for (int i = 0; i < n; ++i)
                result += flow[s][i];
            return result;
        }
    }
 
 
 
 
 
 
 
 
 
 
    static class CustomType{
        int gcd(int a, int b)
        {
            if(a == 0 || b == 0) return a+b; // base case
            return gcd(b,a%b);
        }
 
 
        int[] extendedEuclid(int a,int b) {
            int[] dxy = new int[3];
            if (b ==0){
                dxy[0] =a; dxy[1] =1; dxy[2] =0;
 
                return dxy;
            }
            else{
                int t, t2;
                dxy = extendedEuclid(b, a%b);
                t =dxy[1];
                t2 =dxy[2];
                dxy[1] =dxy[2];
                dxy[2] = t - a/b *t2;
 
                return dxy;
            }
        }
 
 
 
        int invMod(int num,int mod)
        {
            int ptr[] =extendedEuclid (num, mod);
            return ptr[1]+mod;
        }
 
 
 
 
 
    }
 
 
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
        public long nextLong() {
            return Long.parseLong(next());
        }
 
    }
}
 
 