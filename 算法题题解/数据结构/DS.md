## 有关数据结构中的书的问题的一个笔记:

### 树的建立

1. 首先是根据树的后序遍历和中序遍历构建一颗二叉树的问题:

       代码速记?有三个位置的值是可以确定的的？同时
       发现？左子树的ll1,lr1,右子树的rl1,
       rr1 与根
       的(l1,r1)关系?(ll1,rr1+1)==(l1,r1)?类推？


        void creat(Bitree &bt,int l1,int r1,int l2,int r2)
        {
            if(l1>r1||l2>r2) return ;
            bt=new node;
            bt->left=NULL;
            bt->right=NULL;
            bt->data=a[r1];
            int id=pos[a[r1]];
            // left  1    ,l2,id-1    
            creat(bt->left,l1,id+l1-l2-1,l2,id-1);
            // right   ,r1-1,pos[a[r]]+1,r2;
            creat(bt->right,r1+id-r2,r1-1,id+1,r2);
        }

2.其次是根据树的前序遍历和中序遍历构建一颗二叉树的问题





### 树的遍历








4.层序遍历

        void bfs(Bitree &bt)
        {
            while(q.size())
            {
                auto t=q.front();q.pop();
                ans.push_back(t->data);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }


### 树的操作




### 判断一颗树是否为二叉排序树。