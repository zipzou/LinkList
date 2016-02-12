/************************************************************************
* Copyright (C) 2016, Frank
* Filename: main.c
* Author: Frank
* Version: 1.0
* Date: 2016/01/01 19:30
* Description: 
* 
* You can go through this source file writen by C, and we show you the way to construct the link list. 
* And you can get some new functions provided by Windows or C99. And you should pay	attention to the 
* style of code. And every object is referenced by pointer, so you should know how to use the pointer 
* suitably and safely. Aside from all of these, you should learn to write annotations for functions 
* as you can.
* 
* To make your functions clearly like these. The function to realize some operations is not expected 
* to include much input and output. So the functions are clearlier than others mixt with input such as
* 'scanf("")' and 'printf("")'. If you did, you may not know what the function wants to do, and what it
* can to. So it is not a sensible choice.
* 
* To make your input and output combined with main function, the entry of console applications. Because 
* if you get a source file, you will find entry at once and read it. And input and output are tips for readers,
* so readers can know what the statement stands for. Then the code is so clearly to read! Just do it!
* 
* If there are some errors you have found and you can't resolve them, please contact me. Or you will
* have some questions about this source file, please contact me any way as you can.
*
* Now You should have patient with your reading...
************************************************************************/

// main.c

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#ifndef TRUE
#define TRUE 1
#endif // !TRUE
#ifndef FALSE
#define FALSE 0
#endif //!FALSE
#ifndef NULL
#define NULL 0
#endif // !NULL
#ifndef NODE_NOT_FOUND
#define NODE_NOT_FOUND -1 
#endif // !NODE_NOT_FOUND
#ifndef SIZE_STUDENT
#define SIZE_STUDENT sizeof(Student)
#endif // !SIZE_STUDENT
typedef unsigned int Rank;
typedef struct Student
{
	char name[20];
	int age;
	struct Student *next;
	struct Student *last;
}Student, *PLinkHead, *PLinkNode;
typedef int BOOL;

// If you want, you can remove your statements to another new header file, and create a new 
// source file to realize every function.

/*
	To display information about student
	* @param student The student you want to display.
*/
void display(Student * student);

/* 
	Create a link list with head node empty.
	* @return Return the head of link list created. If you have get NULL, it stands for allocate failed.
*/
PLinkHead createLinkListHeadEmpty();

/*
	To insert a node into the link list.
 * @param stu_node The student to insert into the link list.
 * @param _link_list_head The destination inserted into.
 * @return Return the state of execute result.
*/
BOOL addNodeToLinkList(Student * stu_node, PLinkHead _link_list_head);

/*
	To judge whether the link list is empty.
	If you have got FALSE, it will tell you the link list isn't empty.
	Or The link list is empty.
	* @param _link_head The head of the link list.
	* @return Return the result.
*/
BOOL isEmpty(PLinkHead _link_head);

/*
	To judge whether the node is the last one.
	If you get TRUE, then the node is the last one.
	* @param stu The node you will judge.
	* @param _link_head The head of the link list.
	* @return Return the result.
*/
BOOL isLastOne(PLinkNode stu, PLinkHead _link_head);

/*
	To get the size of the link list.
	* @param _link_head The head of the link list destination.
	* @return Return the size of the link list, and you can use this value to find it empty or not.
*/
size_t linkListSize(PLinkHead _link_head);

/*
	To remove a node you appoint in the link list.
	* @param stu_node The student you will remove from the link list.
	* @param _link_head The head of the link list destination.
	* @return Return the state after removed.
*/
BOOL removeNodeInLinkList(Student * stu_node, PLinkHead _link_head);

/*
	To remove a node by index.
	You should ensure the index is right, or it will be failed.
	* @param index The index you want to remove.
	* @param _link_head The head of link list destination.
	* @return Return the state after removed.
*/
BOOL removeNodeAt(Rank index, PLinkHead _link_head);
/*
	Respond to the test on two students.
	* @param origin_stu The first student to compare.
	* @param dest_stu The second student to compare.
	* @return Return the test result.If you get TRUE, it will stand for equal.
*/
BOOL isEqualBetweenStudents(Student * origin_stu, Student * dest_stu);
/*
	To find the student being equal with the student you appoint.
	* @param stu_node The student you are about to find.
	* @param _link_head The head of link list which you want to find in.
	* @return Return the pointer of the node found.If you get NULL, it will stand for failing to find.
*/
PLinkNode findInLinkList(Student * stu_node, PLinkHead _link_head);
/*
	Find the index of the student in the link list.
	* @param stu_node The student you are about to find.
	* @param _link_head The head of link list.
	* @return Return the index of the student you appoint. If you get NODE_NOT_FOUNT, it will stand for there is such node in the link list as 
				the student you appoint.
*/
Rank indexOf(Student * stu_node, PLinkHead _link_head);
/*
	Get the student by index.
	You should ensure the index is right and not out of range.
	* @param index The index you want to get.
	* @param _link_head The head of link list.
	* @return Return the student you want to get.If you get NULL, it may be the index out of range.
*/
PLinkNode at(Rank index, PLinkHead _link_head);

/*
	Clear all nodes in the link list.
	Attention: Please call it after you used the link list. And make the header NULL to avoid wild pointer.
	* @param _link_head The head of link list destination.
	* @return Return the count of nodes cleaned.
*/
size_t clearLinkList(PLinkHead  _link_head);

/*
	To get the first student in the link list.
	* @param _link_head The head of the link list.
	* @return Return the first Student. If the link list is empty, you will get NULL.
*/
Student *first(PLinkHead _link_head);

// entry of program
int main()
{
	int _count = 0; // the count of student
	PLinkHead linkHead = NULL;
	printf("Input count of the students you have: ");
	scanf("%d", &_count);
	// If you want, you can add a statement like this: system("cls"); supported by Windows and you'd better include the file 'stdlib.h'.
	printf("Yes, you have inputed the count, then you can input the information about these students and we will construct a link list for you,\
 so that you can get a head pointer for this link list! \n\n");
	if (!linkHead) // if the link list is not been constructed
	{
		linkHead = createLinkListHeadEmpty();
	}
	for (int i = _count - 1; i >= 0; i--)// you should know this way is more efficient than another way as "i = 0; i < _count; i++"
	{
		printf("Now you'd better make No.%d student's information clearly! \n\n", _count - i);
		// Let's flush the buffer in the memory first.
		fflush(stdin);
		printf("Now, give us the name of the student :");
		char _name_buf[100] = { 0 }; // the buffer to load the name, initialed with an empty string.
		scanf("%s", _name_buf);
		printf("Okay, good, you should give us the age of this student now£º");
		int _age = -1; // statement of age
		scanf("%d", &_age);
		printf("\n\n");
		// construct a student object
		Student *stu = (Student *)malloc(SIZE_STUDENT); 
		strcpy_s(stu->name, 20u, _name_buf);// This is a safe function, because you must give the length of destination buffer.
		// If you want to use strcpy(char *_Dest_Buf, const char *_Source_Buf), you must ensure the size is suitable for destination buffer, 
		// or you would damage the memory and then unexpected error happened!
		stu->age = _age;
		BOOL res = addNodeToLinkList(stu, linkHead); // insert it to the link list
		if (!res)
		{
			printf("Warning: There is a problem when we push the student into the link list. But we can't get any information for this error, so we \
canceled this operation for you!\n");
		}
	}

	printf("Now you have get the link list, you can do something you want!\n");
	// TODO: Insert codes to handle the link list constructed by your information.
	// Examples:
	// Show All
	Student *curStudent = first(linkHead);
	printf("\n\nYou can see all students listed as below!\n\n");
	while (!isLastOne(curStudent, linkHead))
	{
		display(curStudent);
		curStudent = curStudent->next;
	}
	curStudent = NULL;
	// Remove a node at 0
	if (!isEmpty(linkHead))
	{
		removeNodeAt(0, linkHead);
	}
	// Now let's have a test and review the information in the link list.
	printf("\n\nNow let's have a test and review the information in the link list.\n\n");
	curStudent = first(linkHead);
	while (!isLastOne(curStudent, linkHead))
	{
		display(curStudent);
		curStudent = curStudent->next;
	}
	curStudent = NULL;

	// You can find a node as you want...

	// At the end, you should free all nodes after you don't need these datas. It's a good habit!
	clearLinkList(linkHead);
	// Don't forget make header NULL or there will be a wild pointer, which is unsafe!
	linkHead = NULL;
	printf("\n\nHave you saw the result after the node 0 removed?\n\n");
	//system("pause");// this statement is supported by Windows if you want to make screen pause.
	return 0;
}

PLinkHead createLinkListHeadEmpty()
{
	PLinkHead  head = NULL;
	PLinkHead tail = NULL;
	head = (PLinkHead)malloc(SIZE_STUDENT);
	tail = (PLinkHead)malloc(SIZE_STUDENT);
	head->next = tail;
	head->last = NULL;
	tail->last = head;
	tail->next = NULL;
	return head;
}

BOOL addNodeToLinkList(Student * stu_node, PLinkHead _link_list_head)
{
	if (!_link_list_head || !stu_node) // if the link list is not existent or student is not been initialied, failed.
	{
		return FALSE;
	}
	// insert as the last one
	PLinkNode curNode = _link_list_head->next;
	while (curNode->next != NULL)
	{
		curNode = curNode->next;
	}
	// get the last position, and begin to insert
	curNode->last->next = stu_node;
	stu_node->last = curNode->last;
	curNode->last = stu_node;
	stu_node->next = curNode;
	return TRUE;
}

BOOL isEmpty(PLinkHead _link_head)
{
	if (!_link_head) // if the link list is not existent
	{
		return TRUE;
	}
	if (_link_head->next->next == NULL) // the head and the tail are guard without data 
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL isLastOne(PLinkNode stu, PLinkHead _link_head)
{
	if (!stu || !_link_head)
	{
		return TRUE;
	}
	if (!stu->next)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

size_t linkListSize(PLinkHead _link_head)
{
	size_t _size = NODE_NOT_FOUND;
	if (!_link_head) // if the link list is not existent
	{
		return _size;
	}
	PLinkNode curNode = _link_head->next;
	while (curNode->next) // if there is a node after the current node, then the current node is not the last one
	{
		_size++; // increase when node founded
	}
	return _size;

}

BOOL removeNodeInLinkList(Student * stu_node, PLinkHead _link_head)
{
	if (!_link_head) // if the link list is not existent
	{
		return FALSE;
	}
	if (isEmpty(_link_head))
	{
		return FALSE;
	}

	// step 1: find the node to remove
	PLinkNode curNode = _link_head->next;
	while (curNode->next)
	{
		if (isEqualBetweenStudents(stu_node, curNode)) // to find the node appointed
		{
			break;
		}
	}
	if (!curNode->next) // if not found
	{
		return FALSE;
	}
	// step 2: begin to remove
	curNode->last->next = curNode->next;
	curNode->next->last = curNode->last;

	// step 3: begin to free the node removed
	free(curNode);
	// step 4: begin make pointer NULL for safety
	curNode = NULL;
	return TRUE;
}

BOOL removeNodeAt(Rank index, PLinkHead _link_head)
{
	if (index < 0) // illegal index
	{
		return FALSE;
	}
	if (!_link_head) // if the link list is not existent
	{
		return FALSE;
	}
	int curIndex = 0;
	PLinkNode curNode = at(index, _link_head);
	if (!curNode)
	{
		return FALSE;
	}

	// remove
	curNode->next->last = curNode->last;
	curNode->last->next = curNode->next;
	free(curNode);
	curNode = NULL;
	return TRUE;
}

BOOL isEqualBetweenStudents(Student * origin_stu, Student * dest_stu)
{
	// TODO : insert codes to state condition where students are equal.
	// example:
	if (!origin_stu || !dest_stu) // if the pointer is NULL
	{
		return FALSE;
	}
	if (strcmp(origin_stu->name, dest_stu->name) == 0 && origin_stu->age == dest_stu->age) // to state condition
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

PLinkNode findInLinkList(Student * stu_node, PLinkHead _link_head)
{
	PLinkNode foundNode = NULL;
	if (!stu_node || !_link_head) // if the studetn is NULL or the link list is not existent
	{
		return foundNode;
	}
	foundNode = _link_head->next;
	while (foundNode->next)
	{
		if (isEqualBetweenStudents(stu_node, foundNode))
		{
			break;
		}
	}
	if (!foundNode->next) // end with tail, not found
	{
		return NULL;
	}
	return foundNode;
}

Rank indexOf(Student * stu_node, PLinkHead _link_head)
{
	Rank curIndex = 0;
	if (!stu_node || !_link_head) // the student is null or the link list is not existent
	{
		return NODE_NOT_FOUND;
	}
	PLinkNode curNode = _link_head->next;
	while (curNode->next)
	{
		if (isEqualBetweenStudents(stu_node, curNode))
		{
			break;
		}
		curIndex++; // increase when they are not equal
	}
	if (!curNode->next) // end with tail, and find failed
	{
		return NODE_NOT_FOUND;
	}
	return curIndex;
}

PLinkNode at(Rank index, PLinkHead _link_head)
{
	if (index < 0) // illegal index
	{
		return FALSE;
	}
	if (!_link_head) // if the link list is not existent
	{
		return FALSE;
	}
	unsigned int curIndex = 0;
	PLinkNode curNode = _link_head->next;
	while (curNode->next) // to find index
	{
		if (curIndex >= index)
		{
			break;
		}
	}
	if (curIndex < index || curIndex > index) // the index is out of range or mistake when iterated
	{
		return NULL;
	}
	if (!curNode->next)
	{
		return NULL;
	}
	return curNode;
}

size_t clearLinkList(PLinkHead  _link_head)
{
	size_t _count_del = 0;
	if (!_link_head) // if the link list is not existent
	{
		return _count_del;
	}
	PLinkNode curNode = _link_head->next;
	while (curNode->next) // to remove student except guard pointer
	{
		PLinkNode temp = NULL;
		temp = curNode->next; // for next iteration
		// remove
		curNode->last->next = curNode->next;
		curNode->next->last = curNode->last;
		free(curNode);
		// next
		curNode = temp;
		// make count increase
		_count_del++;
	}
	// to remove guard pointer
	PLinkHead head = _link_head;
	PLinkNode tail = curNode;
	free(head);
	free(tail);
	head = NULL;
	tail = NULL;
	return _count_del;
}

void display(Student * student)
{
	// TODO: Insert codes to state format output.
	// Example:
	printf("I'm a student with named %s and %d year-old. \n", student->name, student->age);
}

Student *first(PLinkHead _link_head)
{
	if (!_link_head)
	{
		return NULL;
	}
	if (isEmpty(_link_head)) 
	{
		return NULL;
	}
	return _link_head->next;
}
