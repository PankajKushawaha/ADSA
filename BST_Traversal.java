import java.util.Scanner;
class Node 
{
int key;
Node left, right;
public Node(int item) 
{
key = item;
left = right = null;
}
}
class BinarySearchTree 
{
Node root;
BinarySearchTree() 
{
root = null;
}
public void insert(int key) 
{
root = insertRec(root, key);
}
private Node insertRec(Node root, int key) 
{
if (root == null) {
root = new Node(key);
return root;
}
if (key < root.key) 
{
root.left = insertRec(root.left, key);
} 
else if (key > root.key) 
{
root.right = insertRec(root.right, key);
}
return root;
}

public void inorder() 
{
inorderRec(root);
}
private void inorderRec(Node root) 
{
if (root != null) 
{
inorderRec(root.left);
System.out.print(root.key + " ");
inorderRec(root.right);
}
}
public void preorder() 
{
preorderRec(root);
}
private void preorderRec(Node root) 
{
if (root != null) 
{
System.out.print(root.key + " ");
preorderRec(root.left);
preorderRec(root.right);
}
}
public void postorder() 
{
postorderRec(root);
}
private void postorderRec(Node root)
{
if (root != null) 
{
postorderRec(root.left);
postorderRec(root.right);
System.out.print(root.key + " ");
}
}
public Node search(int key) 
{
return searchRec(root, key);
}
private Node searchRec(Node root, int key) 
{
if (root == null || root.key == key)
return root;
if (key < root.key)
return searchRec(root.left, key);
return searchRec(root.right, key);
}
}

public class BST_Traversal
{
public static void main(String[] args) 
{
BinarySearchTree tree = new BinarySearchTree();
Scanner sc = new Scanner(System.in);
System.out.println("Enter the number of elements you want to insert: ");
int n = sc.nextInt();
for (int i = 0; i < n; i++) 
{
System.out.println("Enter element " + (i + 1) + ":");
int data = sc.nextInt();
tree.insert(data);
}
System.out.println("Inorder traversal:");
tree.inorder(); // Expected: 20 30 40 50 60 70 80
System.out.println("\nPreorder traversal:");
tree.preorder(); // Expected: 50 30 20 40 70 60 80
System.out.println("\nPostorder traversal:");
tree.postorder(); // Expected: 20 40 30 60 80 70 50
System.out.println("\nEnter the number to search: ");
int key = sc.nextInt();
Node result = tree.search(key);
if (result != null) 
{
System.out.println("Element found: " + result.key);
}
else
{
System.out.println("Element not found"); 
}
}
}
