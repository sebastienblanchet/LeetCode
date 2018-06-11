 public void bfs(int[][]matrix, Queue<int[]> queue, boolean[][]visited){
        int n = matrix.length,
        m = matrix[0].length;
        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            for(int[] d:dir){
                int x = cur[0]+d[0];
                int y = cur[1]+d[1];
                if(x<0 || x>=n || y<0 || y>=m || visited[x][y] || matrix[x][y] < matrix[cur[0]][cur[1]]){
                    continue;
                }
                visited[x][y] = true;
                queue.offer(new int[]{x, y});
            }
        }
    }


import Queue

def bfs(matrix, queue, visited):

    # col length
    n = len(matrix)

    # row length
    m = len(matrix[0])

    # while queue is not empty
    while queue:
        current = queue.get()

        for direction in directions:
            x = current[0] + d[0]
            y = current[1] + d[1]
            if x<0 or x>=n or y<0 or y>=m or visited[x][y] or matrix[x][y] < matrix[current[0]][current[1]]:
                continue
            visited[x][y] = True
            queue.put([x,y])



 public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new LinkedList<>();
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0){
            return res;
        }
        int n = matrix.length, m = matrix[0].length;
        //One visited map for each ocean

        boolean[][] pacific = new boolean[n][m];
        boolean[][] atlantic = new boolean[n][m];

        Queue<int[]> pQueue = new LinkedList<>();
        Queue<int[]> aQueue = new LinkedList<>();

        for(int i=0; i<n; i++){ //Vertical border
            pQueue.offer(new int[]{i, 0});
            aQueue.offer(new int[]{i, m-1});
            pacific[i][0] = true;
            atlantic[i][m-1] = true;
        }
        for(int i=0; i<m; i++){ //Horizontal border
            pQueue.offer(new int[]{0, i});
            aQueue.offer(new int[]{n-1, i});
            pacific[0][i] = true;
            atlantic[n-1][i] = true;
        }
        bfs(matrix, pQueue, pacific);
        bfs(matrix, aQueue, atlantic);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacific[i][j] && atlantic[i][j])
                    res.add(new int[]{i,j});
            }
        }
        return res;


def pacificAtlantic(matrix):

    ans = []

    # col length
    n = len(matrix)

    # row length
    m = len(matrix[0])

    if not matrix or n ==0 or m==0: return ans
