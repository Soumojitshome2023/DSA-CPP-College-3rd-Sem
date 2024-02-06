/*==========================================================================

Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules:

* Only one disk can be moved at a time.
* Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
* No disk may be placed on top of a smaller disk.


Input: 2
Output: Disk 1 moved from A to B
Disk 2 moved from A to C
Disk 1 moved from B to C

Input: 3
Output: Disk 1 moved from A to C
Disk 2 moved from A to B
Disk 1 moved from C to B
Disk 3 moved from A to C
Disk 1 moved from B to A
Disk 2 moved from B to C
Disk 1 moved from A to C

==========================================================================*/

// c++ program to implement tower of hanoi problem
#include <iostream>
using namespace std;

// recursive funtion
void TowerOfHanoi(int num, char A, char B, char C)
{
    if (num > 0)
    {
        TowerOfHanoi(num - 1, A, C, B);
        cout << "Move a disk " << num << " from "
             << " " << A << " to"
             << " " << C << endl;
        TowerOfHanoi(num - 1, B, A, C);
    }
}

// ============================ Main ============================
int main()
{
    int numOfDisk;
    cout << "Enter the no. of disks : ";
    cin >> numOfDisk;

    // calling recursive funtion
    TowerOfHanoi(numOfDisk, 'A', 'B', 'C');
    // A is the source rod , C is destination rod ,B is auxiliary rod
    cout << endl;
}

// =======================================================================