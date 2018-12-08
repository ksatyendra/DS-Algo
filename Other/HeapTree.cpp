#include <bits/stdc++.h>

using namespace std;

typedef struct HeapNode{
    int data;
    HeapNode * left, *right;
}* hptr;
int height(hptr root){
    if(!root) return -1;
    else return(1+max(height(root->left), height(root->right)));
}
void levelPrint(hptr root, int lev){
    if(!root) return;
    if(lev==0)
        printf("%d ", root->data);
    else{
        levelPrint(root->left, lev-1);
        levelPrint(root->right, lev-1);
    }
}
hptr insert(hptr root , int key){
    if(!root){
        root = new HeapNode;
        root->data = key;
        root->left = root->right = NULL;
        return root;
    }
    if(key > root->data)
}
hptr deleteRoot(hptr root){

}
void display(hptr root){
    int ht = height(root);
    printf("\nDisplaying Sorted Node\n");
    for(int i=0; i<= ht; i++)
        levelPrint(root , i);
    printf("\n--------------------------------\n");
}
int main(){
    int ans,key;
    hptr root = NULL;
    while(1){
        printf("\n1 .Insert\n2 .Delete\n.3 Print\n4 .Exit\n\t Select : ");
        cin>>ans;
        switch(ans){
        case 1:
            printf("Enter Key : ");
            cin>>key;
            root = insert(root, key);
            break;
        case 2:
            root = deleteRoot();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nQuitting ----\n\n");
            return 0;
        default:
            printf("\nWrong Choice !!\n");
            break;
        }
    }
    return 0;
}
