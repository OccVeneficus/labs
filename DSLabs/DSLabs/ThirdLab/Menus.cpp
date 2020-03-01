#include "DataInOutLab3.h"
#include "RingBuffer.h"
#include "Stack.h"
#include "TwoStackQueue.h"
#include "Menus.h"
#include "RingBufferQueue.h"
#include "../Common/IntegerReading.h"

void RingBufferMenu()
{
	RingBuffer ringBufferParameters;
	int value;
	CreateRingBuffer(&ringBufferParameters);
	int menuItem;
	do
	{
		BufferPrinting(&ringBufferParameters);
		BufferMenuPrinting();
		do
		{
			cout << "\nChoose number from list above(integer only):";
			menuItem = ReadValue();
		} while (menuItem > 4 || menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				system("cls");
				cout << "Current free space is " << ringBufferParameters.FreeSpace
					<< '.' << endl;
				break;
			}
			case 2:
			{
				system("cls");
				cout << "Current occupied space is " <<
					ringBufferParameters.OccupiedSpace << '.' << endl;
				break;
			}
			case 3:
			{
				cout << "Enter value you to put into buffer." << endl;
				value = ReadValue();
				RingBufferPut(&ringBufferParameters, value);
				system("cls");
				break;
			}
			case 4:
			{
				system("cls");
				if (ringBufferParameters.FreeSpace == ringBufferParameters.BufferSize)
				{
					cout << "Buffer is empty.";
					break;
				}
				value = RingBufferGet(&ringBufferParameters);
				cout << "Value " << value << " pulled from buffer." << endl;
				break;
			}
		}
	} while (menuItem != EXIT_MENU_ITEM);
	RingBufferDelete(&ringBufferParameters);
	system("cls");
}

void StackMenu(Stack *currentStack)
{
	int menuItem;
	do
	{
		int value;
		StackPrinting(currentStack);
		StackMenuPrinting();
		do
		{
			cout << "Choose number from list above(integer only):";
			menuItem = ReadValue();
		} 
		while (menuItem > 3 || menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				system("cls");
				cout << "Enter value(integer only):";
				value = ReadValue();
				PushInStack(currentStack, value);
				break;
			}
			case 2:
			{
				system("cls");
				if (currentStack->Empty)
				{
					break;
				}
				PopFromStack(currentStack);
				break;
			}
			case 3:
			{
				system("cls");
				DeleteStack(currentStack);
				break;
			}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
	system("cls");
}

void TwoStackQueueMenu()
{
	TwoStackQueue queue;
	CreateStack(&queue.ToPush);
	CreateStack(&queue.ToPop);
	int menuItem;
	int value;
	do
	{
		TwoStackQueuePrinting(&queue.ToPop, &queue.ToPush);
		TwoStackQueueMenuPrinting();
		do
		{
			cout << "Choose number from the list above(integer only):";
			menuItem = ReadValue();
		} 
		while (menuItem > 2 || menuItem < 0);
		switch (menuItem)
		{
			case 1:
			{
				system("cls");
				cout << "Enter value(integer only):";
				value = ReadValue();
				PushToTwoStack(&queue, value);
				break;
			}
			case 2:
			{
				system("cls");
				if (queue.ToPop.Empty && queue.ToPush.Empty)
				{
					cout << "\aEmpty." << endl;
					break;
				}
				else
				{
					int valueGet = GetFromTwoStack(&queue);
					cout << valueGet << " Poped from queue.\n";
					break;
				}
			}
		}
	} while (menuItem != EXIT_MENU_ITEM);
	DeleteStack(&queue.ToPop);
	DeleteStack(&queue.ToPush);
	system("cls");
}

void RingBufferQueueMenu()
{
	RingBufferQueue userQueue;
	CreateRingBufferQueue(&userQueue);
	int menuItem;
	int value;
	do
	{
		BufferPrinting(&userQueue.Queue);
		RingQueueMenuPrinting();
		do
		{
			cout << "Choose number from the list above(integer only):";
			menuItem = ReadValue();
		} 
		while (menuItem > 2 || menuItem < 0);
		switch (menuItem)
		{
		case 1:
		{
			system("cls");
			cout << "Enter value(integer only):";
			value = ReadValue();
			RingQueuePut(&userQueue, value);
			break;
		}
		case 2:
		{
			system("cls");
			if (userQueue.Queue.OccupiedSpace == 0)
			{
				cout << "\aEmpty." << endl;
				break;
			}
			else
			{
				int valueGet = RingQueueGet(&userQueue);
				cout << valueGet << " Poped from queue.\n";
				break;
			}
		}
		}
	} 
	while (menuItem != EXIT_MENU_ITEM);
}
