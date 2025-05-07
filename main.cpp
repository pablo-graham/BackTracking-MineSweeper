#include <iostream>
#include <cmath>

#include "MineSweeper/MineSweeper.h"
#include "MineSweeper/TextureSlicerDemo/TextureSlicerDemo.h"
#include "backtracking/Model.h"
#include "randy/NQueens.h"
#include "Trees/BST/BST.h"
#include "Trees/AVL/AVL.h"
#include "Heap/Heap.h"
#include "backtracking/BackTracking.h"

using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
void search(int* arr, int fstIndex, int size, bool& found, int& location, int item);

///================ SORT ==================
void mergeSort(int arr[], int size);
void merge(int arr[], int left[], int leftSize, int right[], int rightSize);
void quickSort(int arr[], int size);
void partition(int arr[],int size,int& pivotIndex);


void printInt(int& data) {
    std::cout << data << " ";
}

int main() {
/*
    BST<int> tree;

    std::cout << "Inserting values...\n";
    tree.push(50);
    tree.push(30);
    tree.push(70);
    tree.push(20);
    tree.push(40);
    tree.push(60);
    tree.push(80);

    std::cout << "\nInorder traversal (should be sorted): ";
    tree.inorder(printInt);

    std::cout << "\nPreorder traversal: ";
    tree.preorder(printInt);

    std::cout << "\nPostorder traversal: ";
    tree.postorder(printInt);

    std::cout << "\nBreadth-first traversal: ";
    tree.breadthorder(printInt);

    std::cout << "\n\nRemoving 50 (root node)...";
    tree.pop(50); // or: tree.remove(50);

    std::cout << "\nInorder traversal after removal: ";
    tree.inorder(printInt);

    std::cout << "\n\nClearing the tree...";
    tree.clear();

    std::cout << "\nInorder traversal after clearing (should be empty): ";
    tree.inorder(printInt);

    std::cout << "\n\nTest complete.\n";
*/
/*
    Heap<int> heap;

    cout << "== Inserting values: 10, 40, 30, 5, 70, 15 ==\n";
    int heapVal[] = {10, 40, 30, 5, 70, 15};
    for (int v : heapVal) {
        heap.push(v);
        cout << "Pushed " << v << ", current top: " << heap.top() << "\n";
    }

    cout << "\n== Heap size: " << heap.getSize() << "\n";

    cout << "\n== Removing elements (should be in descending order):\n";
    while (!heap.empty()) {
        cout << "Top: " << heap.top() << "  -> Removing...\n";
        heap.pop();
    }

    cout << "\n== Attempting to pop from empty heap (should throw):\n";
    try {
        heap.pop();
    } catch (const runtime_error& e) {
        cout << "Caught error: " << e.what() << "\n";
    }

    cout << "\n== Reinsert values for one more check ==\n";
    heap.push(25);
    heap.push(100);
    heap.push(50);
    cout << "Top after reinserts: " << heap.top() << "\n";

    cout << "\n== Test Complete ==\n";


    AVL<int> tree;

    std::cout << "== AVL Tree Insertion ==\n";
    int AVLVal[] = { 30, 20, 40, 10, 25, 50, 5, 15 };
    for (int val : AVLVal) {
        tree.push(val);
    }

    std::cout << "\n== Tree Structure After Insertion ==\n";
    tree.printTree();

    std::cout << "\n== Inorder Traversal (should be sorted) ==\n";
    tree.setTraversalOrder(Traversal::INORDER);
    tree.print(printInt);

    std::cout << "\n== Preorder Traversal ==\n";
    tree.setTraversalOrder(Traversal::PREORDER);
    tree.print(printInt);

    std::cout << "\n== Postorder Traversal ==\n";
    tree.setTraversalOrder(Traversal::POSTORDER);
    tree.print(printInt);

    std::cout << "\n== Remove Node 20 ==\n";
    tree.remove(20);

    std::cout << "\n== Tree Structure After Removal ==\n";
    tree.printTree();

    tree.setTraversalOrder(Traversal::INORDER);
    tree.print(printInt);

    std::cout << "\n== Test with Lambda (double values) ==\n";
    tree.setTraversalOrder(Traversal::INORDER);
    tree.print([](int& x) {
        std::cout << (x * 2) << " ";
    });

    std::cout << "\n== Clearing Tree ==\n";
    tree.clear();
    tree.printTree(); // Should show nothing
    tree.print(printInt);      // Should print nothing

    std::cout << "\n== Test Complete ==\n";

*/
    Model game;

    BackTracking solve(&game);

    if (solve.solve()) {
        cout << "Solution found!\n";
    } else {
        cout << "No solution found!\n";
    }
    game.run();



///quick and merge sorts
/*
int arr[] = {1, 4, 67, 23, 5};
    cout << "premerge: {";
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << "}\n";

    mergeSort(arr, 5);

    cout << "merged: {";
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << "}\n";

    int arr2[] = {6, 4, 67, 23, 5};
    cout << "preQuickSort: {";
    for(int i = 0; i < 5; i++){
        cout << arr2[i] << " ";
    }
    cout << "}\n";

    quickSort(arr2 ,5);

    cout << "quickSorted: {";
    for(int i = 0; i < 5; i++){
        cout << arr2[i] << " ";
    }
    cout << "}\n";

*/
/*
 * MineSweeper game;
game.run();
 */
/*
//    TextureSlicerDemo demo;
//    demo.run();

//
//    int ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    bool isFound;
//    int indexOfItem;
//    int lookForThis = 8;
//
//    std::cout << "looking for "<< lookForThis << ", size is " << 9 << std::endl;
//    search(ints, 0, 9, isFound, indexOfItem, lookForThis);
//    if(isFound){
//        std::cout << lookForThis << " was found on index: " << indexOfItem << std::endl;
//    }else{
//        std::cout << "not found" << std::endl;
//    }

 */

    return 0;
}

void quickSort(int arr[], int size) {
    int pivotIndex;
    if(size > 1) {
        partition(arr, size, pivotIndex);
        int leftSize = pivotIndex;
        int rightSize = size - leftSize - 1;

        quickSort(arr, leftSize);
        quickSort(arr + pivotIndex + 1, rightSize);
    }
}

void partition(int arr[], int size, int& pivotIndex) {
    int pivot = arr[0];
    int i = 1;
    int j = size - 1;

    while(true) {
        while(i < size && arr[i] < pivot) {
            i++;
        }

        while(j > 0 && arr[j] > pivot) {
            j--;
        }
        if(i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        } else {
            break;
        }
    }

    arr[0] = arr[j];
    arr[j] = pivot;
    pivotIndex = j;
}

void mergeSort(int arr[], int size) {
    if (size > 1) {
        int mid = size / 2;

        int left[mid];
        int right[size - mid];

        for (int i = 0; i < mid; i++)
            left[i] = arr[i];
        for (int i = mid; i < size; i++)
            right[i - mid] = arr[i];

        mergeSort(left, mid);
        mergeSort(right, size - mid);

        merge(arr, left, mid, right, size - mid);
    }
}
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void search(int* arr, int fstIndex, int size, bool& found, int& location, int item){
    std::cout << "first index: " << fstIndex << ", size = " << size << std::endl;
    std::cout << "looking at index " << fstIndex + (size / 2) << std::endl;

    if(arr[fstIndex + (size / 2)] == item){
        found = true;
        location = fstIndex + (size / 2);
        std::cout << item << " found in the middle" << std::endl;
    }else if(size == 0){
        found = false;
        location = -1;
        std::cout << "size = 0" << std::endl;

    }else if(arr[(fstIndex + size) / 2] < item){
        std::cout << arr[(fstIndex + size) / 2] << " is less than " << item << ", search right side, size is now " << (size)/2  << std::endl;
        search(arr, fstIndex + (size / 2), int((size)/2), found, location, item);
    }else{
        std::cout << arr[(fstIndex + size) / 2]<<  " is more than " << item << ", search left side, size is now " << size/2  << std::endl;
        search(arr, fstIndex, int(size/2), found, location, item);
    }
    return;
}

//// TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
//// <b>lang</b> variable name to see how CLion can help you rename it.
//auto lang = "C++";
//std::cout << "Hello and welcome to " << lang << "!\n";
//
//for (int i = 1; i <= 5; i++) {
//// TIP Press <shortcut actionId="Debug"/> to start debugging your code.
//// We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/>
//// breakpoint for you, but you can always add more by pressing
//// <shortcut actionId="ToggleLineBreakpoint"/>.
//std::cout << "i = " << i << std::endl;
//}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.