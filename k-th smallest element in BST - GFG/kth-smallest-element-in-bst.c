// { Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define N 100000

struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};

struct Node *createNewNode(int value) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *tree, int val) {

    if (tree == NULL) {
        return createNewNode(val);
    }

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

struct Node *convert_str_to_num(char str[]) {
    char *token = strtok(str, " ");

    struct Node *root = NULL;

    while (token != NULL) {
        int num = atoi(token);
        if (num != 0) {
            root = insert(root, num);
        }
        token = strtok(NULL, " ");
    }

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


 // } Driver Code Ends
// User function Template for C
    struct Node *rightMost(struct Node* l, struct Node* curr)
    {
        while(l->right!=NULL && l->right!=curr)
            l=l->right;
        return l;
    }
int printKthSmallest(struct Node* root, int k) {
    struct Node *curr=root;
        int flag = -1;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                if(--k==0)
                    flag = curr->data;
                curr=curr->right;
            }
            else
            {
                struct Node *rm=rightMost(curr->left, curr);
                if(rm->right==NULL)
                {
                    rm->right=curr;
                    curr=curr->left;
                }
                else
                {
                    rm->right=NULL;
                    if(--k==0)
                    flag = curr->data;
                    curr=curr->right;
                }
            }
        }
        return flag;
}

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        while ((getchar()) != '\n')
            ;
        char str[N];
        scanf("%[^\n]s", str);

        struct Node *root = NULL;

        root = convert_str_to_num(str);

        int k;
        scanf("%d", &k);

        int ans = printKthSmallest(root, k);

        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends