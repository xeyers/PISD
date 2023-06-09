#include "bib.h"

void Sznur::wypisz() const
{
    Node* runner = head;
    while(runner != nullptr)
    {
        std::cout << runner->data << " ";
        runner = runner->next;
    }
}

void Sznur::wstaw(const int& number)
{
    Node* nowy = new Node(number);

    if(head == nullptr)
    {
        head = nowy;
    }
    else
    {
        if(number >= head->data)
        {
            nowy->next = head;
            head = nowy;
        }
        else //number < head->data
        {
            Node* previous = nullptr, *current = head;
            while(current != nullptr && number < current->data)
            {
                previous = current;
                current = current->next;
            }

            if(current == nullptr)
            {
                previous->next = nowy;
            }
            else if(current == head)
            {
                nowy->next = head->next;
                head->next = nowy;
            }
            else
            {
                previous->next = nowy;
                nowy->next = current;
            }
        }
    }
    counter++;
}

void Sznur::usun(const int& K)
{
    Node* one = head, *two = one->next, *three; bool whichCase;

    ///obsluga pierwszej trojki ze wzgledu na mozliwa zmiane heada
    if(two != nullptr && two->next != nullptr) three = two->next;
    else return;

    float average = (one->data+two->data+three->data)/3.0f;
    if(average < K)
    {
        head = two;
        delete one;
        whichCase = true;
    }
    else
    {
        one->next = three->next;
        delete two;
        delete three;
        whichCase = false;
    }

    Node* preGroup = nullptr;

    if(whichCase) //ostatnio usunieto pierwszy
    {
        preGroup = three;

        one = three->next;
        if(one != nullptr) two = one->next;
        else return;

        if(two != nullptr) three = two->next;
        else return;

        if(three == nullptr) return;
    }
    else //ostatnio usunieto drugi i trzeci
    {
        preGroup = one;

        one = one->next;
        if(one != nullptr) two = one->next;
        else return;

        if(two != nullptr) three = two->next;
        else return;

        if(three == nullptr) return;
    }

    ///==============================================

    while(true)
    {
        float average = (one->data+two->data+three->data)/3.0f;
        if(average < K)
        {
            preGroup->next = two;
            delete one;
            whichCase = true;
        }
        else
        {
            one->next = three->next;
            delete two;
            delete three;
            whichCase = false;
        }

        if(whichCase) //ostatnio usunieto pierwszy
        {
            preGroup = three;

            one = three->next;
            if(one != nullptr) two = one->next;
            else return;

            if(two != nullptr) three = two->next;
            else return;

            if(three == nullptr) return;
        }
        else //ostatnio usunieto drugi i trzeci
        {
            preGroup = one;

            one = one->next;
            if(one != nullptr) two = one->next;
            else return;

            if(two != nullptr) three = two->next;
            else return;

            if(three == nullptr) return;
        }
    }
    //usuwa 1-wszy element jezeli srednia trojki jest < od K
    //usuwa 2-gi i 3-ci element jezeli srednia trojki jest >= od K
}

Sznur::~Sznur()
{
    Node* killer = nullptr, *runner = head;
    while(runner != nullptr)
    {
        killer = runner;
        runner = runner->next;
        delete killer;
    }
}

void Sznur::przenies()
{
	///dodac licznik elementow
	if(counter < 3) return;
	else
	{
		//ultimate stop porzucony na rzecz liczenia ilosci par
		Node* runner = head; int ilePar = 0;
		while(runner != nullptr && runner->next != nullptr)
		{
			runner = runner->next->next;
			ilePar++;
		}

		runner = head;
		while(runner->next != nullptr)
		{
			runner = runner->next;
		}
		Node* tail = runner; //miedzy ten element a jego nastepny beda wchodzily
							 //te przepinane na koniec

		Node* one = head, *two = one->next, *preGroup = nullptr, *last = nullptr;
		//last jest zawsze na ostatnim oczku ostatniej dopietej
		//na poczatek pary
		//preGroup jest zawsze oczko przed one
		int ileBylo = 0;
		while(one != nullptr  && two != nullptr && ileBylo < ilePar)
		{
			if(one->data == two->data)
			{
				if(preGroup == nullptr) //pierwsza para
				{
					last = two;
					preGroup = two;

					one = preGroup->next;
					if(one != nullptr) two = one->next;
					else two = nullptr;
				}
				else
				{
					preGroup->next = two->next;
					two->next = last->next;
					last->next = one;
					last = two;

					one = preGroup->next;
					if(one != nullptr) two = one->next;
					else two = nullptr;
				}
			}
			else
			{
					one->next = two->next;
					two->next = tail->next; //nullptr dla pierwszej pary
					tail->next = two;

					preGroup = one;
					preGroup->next = one->next;
					one = preGroup->next;
					if(one != nullptr) two = one->next;
					else two = nullptr;
			}
			ileBylo++;
		}
	}
}
