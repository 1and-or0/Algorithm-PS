#include <iostream>
#include <vector>
using namespace std;

int k; // Number of levels
vector<int> inOrder; // Stores the in-order traversal
vector<vector<int>> treeLevels; // Stores nodes at each level

// Recursive function to construct the tree
void buildTree(int start, int end, int level)
{
    if (start > end)
    {
        return; // Base case: stop if there are no more nodes
    }

    int mid = (start + end) / 2; // Middle element as root of current subtree
    treeLevels[level].push_back(inOrder[mid]); // Add the middle element to the current level

    buildTree(start, mid - 1, level + 1); // Recursively build the left subtree
    buildTree(mid + 1, end, level + 1); // Recursively build the right subtree
}

int main()
{
    cin >> k; // Input the number of levels
    inOrder.resize((1 << k) - 1); // Total number of nodes in the complete binary tree

    for (int i = 0; i < inOrder.size(); i++)
    {
        cin >> inOrder[i]; // Input the in-order traversal
    }

    treeLevels.resize(k); // Initialize tree levels

    buildTree(0, inOrder.size() - 1, 0); // Start building the tree

    // Output the tree level by level
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < treeLevels[i].size(); j++)
        {
            cout << treeLevels[i][j] << " "; // Print nodes at each level
        }
        cout << "\n"; // Newline after each level
    }

    return 0;
}
