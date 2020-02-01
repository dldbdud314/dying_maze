# dying_maze
This is a game where you find your way through the maze, playing small quizzes and games on the way

<img src="https://user-images.githubusercontent.com/57944099/73588214-aac0b680-4509-11ea-8dcb-4e3660d5167e.png" width="40%"></img>
<img src="https://user-images.githubusercontent.com/57944099/73588222-b613e200-4509-11ea-9cea-c555f9a0bb2c.png" width="47%"></img>

## We focused on...
### 1. Using important algorithms: DFS/BFS algorithm</br>
**DFS(Depth-First Search)**</br>This is about searching as deeply as you could. Once there is a deadend(if you can't go further), you go back to the latest crossroad(where there were more choice of path) and continue with the search.</br>In order to go back to the crossroad, it is crucial that you store the node you visited by using stack implicitly.</br>However, this search algorithm could be time-consuming in that it implements recursion, especially if the key is in the last node of last path.</br></br>
**BFS(Breadth-First Search)**</br>Breadth-First Search is more about speading to different paths, rather than digging in deeply(like DFS). Therefore, you use queue to store the nodes to visit in the future.</br>This algorithm has advantage in that it is less time-consuming compared to DFS algorithm. However, DFS would perform better if the key node is in the last node of first path.

### 2. Tracking movements with struct array</br>
**Struct** is similar to class, except that it lacks function. That is, it is composed with data **only**.</br>**Array** is a data structure where you could store many data of same type.</br> Therefore, **Struct array** refers to array of struct type.
<pre>
<code>
struct XY{
       int a;
       int b;
    }; //struct
    
struct XY his[MAX_STACK_SIZE]; //struct array 
</code>
</pre>

## Maze Implementation
