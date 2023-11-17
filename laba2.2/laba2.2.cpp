#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <stdlib.h>
#include <time.h>

class Node
{
public:
	int time;
	std::string name;
	Node* next;
	Node* prev;

	Node()
	{
	
	}

	Node(std::string name, int time)
	{
		this->name = name;
		this->time = time;
	}
};

class Taske
{

public:
	Taske()
	{
		head = NULL;
		tail = head;
	}

	void add(std::string name, int time)
	{
		Node* newTask = new Node(name, time);
		if (head == NULL or tail == nullptr)
		{
			head = newTask;
			newTask->next = NULL;
			newTask->prev = NULL;
			tail = head;
		}
		else
		{
			tail->next = newTask;
			newTask->next = NULL;
			newTask->prev = tail;	
			tail = newTask;
		}
		listSize++;
	}
	int GetRandomNumber(int min, int max)
	{
		srand(time(NULL));

		int num = min + rand() % (max - min + 1);

		return num;
	}

	void randomStrGen()
	{
		std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890@#$%^&*<>{}|";
		std::string name;
		int lenght = GetRandomNumber(0, 20);
		int time = GetRandomNumber(1, 5);
		name.resize(lenght);

		for (int i = 0; i < lenght; i++)
			name[i] = charset[rand() % charset.length()];
		add(name, time);
	}
	void FIFO()
    {
		while (head != NULL)
		{
			printTask(head);
			popFirst();
			std::cout << "remained tasks: " << listSize << std::endl;
			std::cout << std::endl;
		}
		std::cout << "tasks complete" << std::endl;
		std::cout << std::endl;
	}

	void LIFO()
	{
		while (tail != NULL)
		{
			printTask(tail);
			popLast();
			std::cout << "amount outher tasks: " << listSize << std::endl;
			std::cout << std::endl;
		}
		std::cout << "tasks complete" << std::endl;
	}
	void print()
	{
		Node* tempNode = head;
		while (tempNode != NULL)
		{
			std::cout << tempNode->name << std::endl;
			tempNode = tempNode->next;
		}
	}

	void printTask(Node* task) 
	{
		std::cout << "task --- " << task->name << " --- task time " << task->time << " moment" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(task->time));
		std::cout << "task complete" << std::endl;
	}

	void amountTasks()
	{
		std::cout << "remained tasks: " << listSize << std::endl;
		std::cout << std::endl;
	}

	void peekFirst()
	{
		std::cout << head->name << std::endl;
		std::cout << std::endl;
	}

	void peekLast()
	{
		std::cout << tail->name << std::endl;
		std::cout << std::endl;
	}

	void deleteFirst()
	{
		head = head->next;
		listSize--;
		if (head == NULL)
			return;
		delete head->prev;
		head->prev = NULL;

	}

	void deleteLast()
	{
		tail = tail->prev;
		listSize--;
		if (tail == NULL)
			return;
		delete tail->next;
		tail->next = NULL;

	}

	Node* popFirst()
	{
		Node* tempNode = head;
		deleteFirst();
		return tempNode;
	}

	Node* popLast()
	{
		Node* tempNode = tail;
		deleteLast();
		return tempNode;
	}

private:
	int listSize = 0;
	Node* head; //first
	Node* tail; //last
};

int main()
{
	Taske task;
	std::string a;

	while (a != "exit")
	{
		std::cout << "Tearlist commands" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "<><><><><><><><><><><><><><><><>" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "LIFO - print with LIFO" << std::endl;
		std::cout << "FIFO - print with FIFO" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "add - add task" << std::endl;
		std::cout << "addRand - add random task" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "print - print taskes" << std::endl;
		std::cout << "amount - output a number of tasks" << std::endl;
		std::cout << "peekF - peek first task" << std::endl;;
		std::cout << "peekL - peek last task" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "popF - delete first task" << std::endl;
		std::cout << "popL - delete last task" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "<><><><><><><><><><><><><><><><>" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "input command:" << std::endl;
		std::cin >> a;

		if (a == "LIFO") { system("cls"); task.LIFO(); }
		if (a == "FIFO") { system("cls"); task.FIFO(); }
		if (a == "add")
		{
			system("cls");
			std::string name;
			int time;
			std::cout << "input name task: ";
			std::cin >> name;
			std::cout << "input time task: ";
			std::cin >> time;
			task.add(name, time);
		}
		if (a == "addRand") {system("cls"); task.randomStrGen();}
		if (a == "print") {system("cls"); task.print();}
		if (a == "amount") {system("cls"); task.amountTasks();}
		if (a == "peekF") {system("cls"); task.peekFirst();}
		if (a == "peekL") {system("cls"); task.peekLast();}
		if (a == "popF") {system("cls"); task.popFirst();}
		if (a == "popL") {system("cls"); task.popLast();}

		task.print();
	}
}

