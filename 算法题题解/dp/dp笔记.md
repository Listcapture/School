#### 背包
1. $0-1$ 背包  $j$从大到小枚举

2. 完全背包  $j$从小到大枚举

3. 考虑前$i$个物品，背包总容量为j时的最大价值  

### 状态转移方程
$$
    f_{i,j}=max(f_{i-1,j},f_{i-1,j-v_i}+w_i) 
$$

4. $n$个物品不选第$i$个物品，背包总容量为$j$时的最大价值

维护两个背包考虑前$i$个物品$pre_{i,j}$，和考虑后i个物品$suf_{i,j}$
   
### 状态转移方程
$$
       f_{i,j}=\underset{k\in[1,j]}{max}\lbrace pre_{i-1,k}+suf_{i+1,j-k}  \rbrace
$$

