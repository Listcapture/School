/// @brief Y总方法
void dfs()
{
    //
    if(s[k]=='#')
    {
      k++;//回溯
      return ;
    }
    char ch=s[k++];//k++相当与跳到左子树，ch是根结点的值，
    dfs();//中序遍历左子树
    cout<<ch<<" ";
    dfs();//中序遍历右子树
    
}


//教材方法
void build(Bitree &bt)
{
  cin>>ch;
  if(ch=='#')
  {
    bt=NULL;
  }else 
  {
    bt=new Tnode;
    bt->data=ch;
    build(bt->left);
    build(bt->right);
  }
}
void inorder(Bitree &bt)
{
  if(bt)
  {
  inorder(bt->left);
  cout<<bt->data<<" ";
  inorder(bt->right); 
  }
}
