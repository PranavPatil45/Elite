#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node *search(struct Node *root, int target)
{
    if (root == NULL || root->data == target)
    {
        return root;
    }
    if (target < root->data)
    {
        return search(root->left, target);
    }
    return search(root->right, target);
}

struct Node *findMin(struct Node *root)
{
    struct Node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void display(struct Node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    display(root);
    printf("\n");

    int target = 40;
    struct Node *result = search(root, target);
    if (result != NULL)
    {
        printf("Target %d found in the tree.\n", target);
    }
    else
    {
        printf("Target %d not found.\n", target);
    }

    root = deleteNode(root, 50);
    display(root);
    printf("\n");

    return 0;
}